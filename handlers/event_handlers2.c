/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 14:33:56 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/13 14:34:05 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
