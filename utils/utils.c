/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:07:33 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/13 15:11:42 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	validate_arguments(int ac)
{
	if (ac != 2)
	{
		write(1, "Error: Invalid number of arguments\n", 35);
		exit(1);
	}
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->window.win, 17, 0, close_game, game);
	mlx_key_hook(game->window.win, handle_key_press, game);
}

int	get_tile_index(t_map *map, int x, int y)
{
	return (y * map->width + x);
}

void	init_mlx(t_game *game)
{
	game->window.mlx = mlx_init();
}

void	calculate_window_size(t_game *game)
{
	game->window.width = game->map.width * TILE_SIZE;
	game->window.height = game->map.height * TILE_SIZE;
	if (game->window.width > WINDOW_MAX_WIDTH)
		game->window.width = WINDOW_MAX_WIDTH;
	if (game->window.height > WINDOW_MAX_HEIGHT)
		game->window.height = WINDOW_MAX_HEIGHT;
}
