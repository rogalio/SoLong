#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>
#include <string.h>
#include "../mlx_mac/mlx.h"
#include <stdarg.h>

# define WINDOW_WIDTH 640
# define WINDOW_HEIGHT 640
# define MLX_ERROR 1
# define NUM_TEXTURES 5
# define MAX_ITEMS 10
# define TILE_SIZE 64
# define MAP_WIDTH 11
# define MAP_HEIGHT 11


# define ERROR_ARG 1
# define ERROR_FILE 2
# define ERROR_ALLOC 3
# define ERROR_LOAD 4
# define ERROR_READ 5
# define ERROR_INIT 6
# define ERROR_MAP 7
# define ERROR_TEXTURE 8
# define ERROR_OPEN 9




typedef struct s_texture
{
    void    *img;
    char    *addr;
    int     width;
    int     line_length;
    int     bits_per_pixel;
    int     endian;
}               t_texture;

typedef enum e_tile
{
    TILE_WALL,
    TILE_EMPTY,
    TILE_ITEM,
    TILE_EXIT,
    TILE_PLAYER
}               t_tile;

typedef struct s_window
{
    void        *mlx;
    void        *win;
    t_texture   texture[NUM_TEXTURES];
}               t_window;

typedef struct s_map
{
    int width;
    int height;
    t_tile *tiles;
}               t_map;

typedef struct s_entity
{
    int x;
    int y;
    int collected;
    t_texture   texture;
}               t_entity;

typedef struct s_error
{
    int code;
    char *message;
}               t_error;

typedef struct s_game
{
    t_window    window;
    t_map       map;
    t_entity    player;
    t_entity    item;
    t_entity    exit;
}               t_game;

typedef struct s_event
{
    int (*func)(int, t_game *);
    int keycode;
}               t_event;




//error
int handle_error(int code, ...);

//utils
int check_args(int ac);
void setup_hooks(t_game *game);
int get_tile_index(t_map *map, int x, int y);
void init_window(t_game *game, int width, int height, char *title);

//event
int close_window(t_window *data, t_map *map);
int move_player(t_game *game, int dx, int dy) ;
int move_up(t_game *game);
int move_down(t_game *game);
int move_left(t_game *game);
int move_right(t_game *game);
int handle_key_press(int keycode, t_game *game);
int check_all_items_gathered(t_game *game);

int check_collision(t_game *game, int new_x, int new_y);

//map utils
int get_tile_index(t_map *map, int x, int y);
int load_map(char *filename, t_game *game);
int draw_map(t_game *game);

//

//game
int init_player(t_game *game);
int init_game(t_game *game, char **av, int ac, char **files);
int load_game_map(t_game *game, char *map_path);


//texture utils
int load_texture(void *mlx_ptr, char *file, t_texture *tex);
int load_all_textures(t_game *game, char **files, int num_files);
int load_game_textures(t_game *game, char **files);
void draw_texture(t_window *data, t_texture *texture, int x, int y);
void clear_texture(t_window *data, int x, int y);
void redraw_texture(t_game *game, int x, int y);

#endif
