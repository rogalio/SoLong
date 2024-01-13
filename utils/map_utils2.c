/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:02:31 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/13 15:08:58 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	update_map_dimensions(char c, int *current_line_width, t_map *map)
{
	if (c == '\n')
	{
		if (map->width == 0)
			map->width = *current_line_width;
		*current_line_width = 0;
		map->height++;
	}
	else
		(*current_line_width)++;
	return (0);
}

int	check_final_dimensions(int current_line_width, t_map *map)
{
	if (current_line_width > 0)
	{
		if (current_line_width == map->width)
			map->height++;
		else
			return (1);
	}
	return (0);
}

int	read_map_size(char *filename, t_map *map)
{
	char	c;
	int		current_line_width;
	int		fd;

	map->width = 0;
	map->height = 0;
	current_line_width = 0;
	fd = open_map(filename);
	while (read(fd, &c, 1) > 0)
	{
		if (update_map_dimensions(c, &current_line_width, map) == 1)
			return (1);
	}
	if (check_final_dimensions(current_line_width, map) == 1)
	{
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}
