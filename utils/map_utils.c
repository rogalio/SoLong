/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:29:51 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/13 15:02:28 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	open_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Error: Map file not found\n", 26);
		exit(1);
	}
	return (fd);
}

int	init_map(t_map *map)
{
	map->tiles = malloc(sizeof(t_tile) * map->width * map->height);
	if (map->tiles == NULL)
	{
		strerror(errno);
		free(map->tiles);
		exit(1);
	}
	return (0);
}

int	read_map(int fd, t_map *map)
{
	char	c;
	int		tile_index;
	ssize_t	ret;

	tile_index = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, &c, 1);
		if (c == '\n')
			continue ;
		map->tiles[tile_index] = c - '0';
		tile_index++;
	}
	if (ret == -1)
	{
		free(map->tiles);
		exit(1);
	}
	return (0);
}

int	load_map(char *filename, t_game *game)
{
	int	fd;

	fd = open_map(filename);
	init_map(&game->map);
	read_map(fd, &game->map);
	close(fd);
	return (0);
}

int	draw_map(t_game *game)
{
	int	x;
	int	y;
	int	tile_index;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			tile_index = get_tile_index(&game->map, x, y);
			draw_texture(&game->window, &game->window.texture
			[game->map.tiles[tile_index]], x, y);
			x++;
		}
		y++;
	}
	return (0);
}
