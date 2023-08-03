/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 12:14:53 by codespace         #+#    #+#             */
/*   Updated: 2023/07/31 19:01:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>


# include "./mlx_linux/mlx.h"

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 640

# define MLX_ERROR 1

# define NUM_TEXTURES 3
# define TILE_SIZE 64

# define MAP_WIDTH 10
# define MAP_HEIGHT 10
# define MAP_SIZE (MAP_WIDTH * MAP_HEIGHT)

typedef struct s_texture
{
    void    *img;
    char    *addr;
    int     width;
    int     line_length;
    int     bits_per_pixel;
    int     endian;
}               t_texture;

typedef struct s_window
{
    void    *mlx;
    void    *win;
     t_texture   texture[NUM_TEXTURES];
}               t_window;

typedef struct s_map
{
    int tiles[MAP_SIZE];
}               t_map;







#endif


/// a faire




