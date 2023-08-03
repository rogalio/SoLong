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
# include <stddef.h>


# include "./mlx_linux/mlx.h"


# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 640

# define MLX_ERROR 1

# define NUM_TEXTURES 5
# define TILE_SIZE 64

# define MAP_WIDTH 11
# define MAP_HEIGHT 11

# define ERROR_ARG 1
# define ERROR_FILE 2
# define ERROR_ALLOC_TILE 3
# define ERROR_LOAD_TILE 4
# define ERROR_READ_FILE 5
# define ERROR_LOAD_TEXTURE 6

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
    void        *mlx;
    void        *win;
    t_texture   texture[NUM_TEXTURES];
}               t_window;

typedef struct  s_map
{
    int *tiles;
    int width;
    int height;
}               t_map;

typedef struct s_player
{
    int x;
    int y;
    t_texture   texture;
}               t_player;

typedef struct  s_item
{
    int         x;
    int         y;
    t_texture   texture;
    int         collected;
}               t_item;


//error
void handle_error(int error_code);

//event
int close_window(t_window *data, t_map *map);
int handle_key_press(int keycode, t_window *data, t_map *map);
int handle_key_release(int keycode, t_window *data, t_map *map);

//map utils
int get_tile_index(t_map *map, int x, int y);
int load_map(char *filename, t_map *map);
void draw_map(t_window *data, t_map *map, t_player *player, t_item *item);

//texture utils
int load_texture(void *mlx_ptr, char *file, t_texture *tex);
int load_all_textures(t_window *data, char **files, int num_textures);
void draw_texture(t_window *data, t_texture *texture, int x, int y);
void draw_player(t_window *data, t_player *player);
void draw_tile(t_window *data, t_map *map, int x, int y);
void draw_item(t_window *data, t_item *item);

#endif





