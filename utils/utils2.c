/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:10:10 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/13 16:13:37 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	initialize_lut(t_game *game)
{
	unsigned char	char0;
	unsigned char	char1;
	unsigned char	char2;
	unsigned char	char3;
	unsigned char	char4;

	char0 = '0';
	char1 = '1';
	char2 = '2';
	char3 = '3';
	char4 = '4';
	game->lut[char0] = 1;
	game->lut[char1] = 0;
	game->lut[char2] = 2;
	game->lut[char3] = 'E';
	game->lut[char4] = 'P';
}

void	translate_map(t_game *game)
{
	int	idx;

	idx = 0;
	while (idx < NUM_TEXTURES)
	{
		game->map.tiles[idx] = game->lut[(unsigned char)game->map.tiles[idx]];
		idx++;
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
