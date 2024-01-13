/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:11:14 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/13 15:11:45 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	create_window(t_game *game, char *title)
{
	game->window.win = mlx_new_window(game->window.mlx,
			game->window.width, game->window.height, title);
}

void	init_window(char *filename, t_game *game, char *title)
{
	init_mlx(game);
	read_map_size(filename, &game->map);
	calculate_window_size(game);
	create_window(game, title);
}

int	validate_map_char(char c)
{
	if (c >= '0' && c <= '4')
		return (0);
	return (1);
}

int	check_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width * map->height)
	{
		if (validate_map_char(map->tiles[i] + '0'))
		{
			write(1, "Error: Invalid map character\n", 30);
			free(map->tiles);
			exit(1);
		}
		i++;
	}
	return (0);
}
