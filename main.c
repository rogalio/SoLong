/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rogalio <rmouchel@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:20:19 by rogalio           #+#    #+#             */
/*   Updated: 2024/01/12 19:22:07 by rmouchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	validate_arguments(ac);
	initialize_lut(&game);
	init_game(&game, av[1]);
	translate_map(&game);
	setup_hooks(&game);
	mlx_loop(game.window.mlx);
	close_game(&game);
	return (0);
}
