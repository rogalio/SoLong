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


# define WINDOW_MAX_WIDTH 1024
# define WINDOW_MAX_HEIGHT 788

# define MLX_ERROR 1
# define NUM_TEXTURES 5
# define MAX_ITEMS 10
# define TILE_SIZE 64

# define GAME_TITLE "So Long"

# define KEY_ESC 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define DIRECTION_UP {-1, 0}
# define DIRECTION_DOWN {1, 0}
# define DIRECTION_LEFT {0, -1}
# define DIRECTION_RIGHT {0, 1}
# define DIRECTION_NONE {0, 0}

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
    int         width;
    int         height;
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
  //  int collected;
    int steps;
    t_texture   texture;
}               t_entity;

typedef struct s_items
{
    t_entity    item[MAX_ITEMS];
    int         collected;
    int         total;
}               t_items;

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
    t_items    items[MAX_ITEMS];
    t_entity    exit;
}               t_game;



// gerer le sevent avec struct ?

typedef struct s_direction
{
    int x;
    int y;
}               t_direction;
typedef struct s_event
{
    int (*callback)(t_game *, t_direction);
    int keycode;
    t_direction direction;
}               t_event;

//error
int handle_error(int code, ...);

//utils
int validate_arguments(int ac);
void setup_hooks(t_game *game);
int get_tile_index(t_map *map, int x, int y);
void init_window(char *filename, t_game *game, char *title);

//intputs
int move_player(t_game *game, t_direction direction);
int handle_key_press(int keycode, t_game *game);
t_event  *get_key_events(void);

//event
int close_window(t_window *data, t_map *map);
void update_position(t_game *game, int new_x, int new_y);
int check_all_items_gathered(t_game *game);
int check_collision(t_game *game, int new_x, int new_y);
int reveal_exit(t_game *game);

//map utils
int get_tile_index(t_map *map, int x, int y);
void setup_hooks(t_game *game);
int read_map_size(char *filename, t_map *map);
int load_map(char *filename, t_game *game);
int draw_map(t_game *game);

//game
int init_player(t_game *game);
int init_game(t_game *game, char *map_path, char **files);

//texture utils
int load_texture(void *mlx_ptr, char *file, t_texture *tex);
int load_all_textures(t_game *game, char **files, int num_files);
void draw_texture(t_window *data, t_texture *texture, int x, int y);
void clear_texture(t_window *data, int x, int y);
void redraw_texture(t_game *game, int x, int y);

#endif
