/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:14:25 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/11 12:28:16 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_window *data, t_map *map)
{
	free(map->tiles);
	mlx_destroy_image(data->mlx, data->texture[TILE_WALL].img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	close_game(t_game *game)
{
	close_window(&game->window, &game->map);
	return (0);
}

void	collect_item(t_game *game)
{
	game->items.collected += 1;
	game->map.tiles[get_tile_index(&game->map,
			game->player.x, game->player.y)] = TILE_EMPTY;
	if (game->items.collected == game->items.total)
		reveal_exit(game);
}

int	reveal_exit(t_game *game)
{
	game->map.tiles[get_tile_index(&game->map, game->exit.x,
			game->exit.y)] = TILE_EXIT;
	draw_texture(&game->window, &game->window.texture[TILE_EXIT],
		game->exit.x, game->exit.y);
	return (0);
}

int	check_collision(t_game *game, int new_x, int new_y)
{
	if (game->map.tiles[get_tile_index(&game->map, new_x, new_y)] == TILE_WALL)
		return (1);
	if (game->map.tiles[get_tile_index(&game->map, new_x, new_y)] == TILE_ITEM)
		collect_item(game);
	if (game->map.tiles[get_tile_index(&game->map, new_x, new_y)] == TILE_EXIT
		&& check_all_items_gathered(game))
		close_window(&game->window, &game->map);
	return (0);
}

int	check_all_items_gathered(t_game *game)
{
	if (game->items.collected == game->items.total)
		return (1);
	return (0);
}

void	update_position(t_game *game, int new_x, int new_y)
{
	game->map.tiles[get_tile_index(&game->map, game->player.x, game->player.y)]
		= TILE_EMPTY;
	clear_texture(&game->window, game->player.x, game->player.y);
	game->player.x = new_x;
	game->player.y = new_y;
	game->map.tiles[get_tile_index(&game->map, game->player.x, game->player.y)]
		= TILE_PLAYER;
	redraw_texture(game, new_x, new_y);
}
