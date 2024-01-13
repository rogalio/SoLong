/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:07:20 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/13 14:46:57 by rogalio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_event	*get_key_events(void)
{
	static t_event	g_key_events[] = {
	{move_player, KEY_UP, {0, -1}},
	{move_player, KEY_DOWN, {0, 1}},
	{move_player, KEY_LEFT, {-1, 0}},
	{move_player, KEY_RIGHT, {1, 0}},
	{NULL, 0, {0, 0}}};

	return (g_key_events);
}

int	move_player(t_game *game, t_direction direction)
{
	int	new_x;
	int	new_y;

	new_x = game->player.x + direction.x;
	new_y = game->player.y + direction.y;
	if (check_collision(game, new_x, new_y))
		return (1);
	update_position(game, new_x, new_y);
	game->player.steps++;
	write(1, "Steps: ", 7);
	ft_putnbr_fd(game->player.steps, 1);
	write(1, "\n", 1);
	return (0);
}

int	handle_key_press(int keycode, t_game *game)
{
	t_event	*event;

	event = get_key_events();
	while (event->callback != NULL)
	{
		if (keycode == event->keycode)
			return (event->callback(game, event->direction));
		if (keycode == KEY_ESC)
			close_game(game);
		event++;
	}
	return (0);
}
