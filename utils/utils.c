#include "../include/so_long.h"

int validate_arguments(int ac)
{
    if (ac != 2)
        return (handle_error(ERROR_ARG));
    return (0);
}

void setup_hooks(t_game *game)
{
    mlx_hook(game->window.win, 17, 0, close_game, game);
    mlx_key_hook(game->window.win, handle_key_press, game);
}

int get_tile_index(t_map *map, int x, int y)
{
    return (y * map->width + x);
}

void init_mlx(t_game *game) {
  game->window.mlx = mlx_init();
}

void calculate_window_size(t_game *game)
{
    game->window.width = game->map.width * TILE_SIZE;
    game->window.height = game->map.height * TILE_SIZE;
    if (game->window.width > WINDOW_MAX_WIDTH)
        game->window.width = WINDOW_MAX_WIDTH;
    if (game->window.height > WINDOW_MAX_HEIGHT)
        game->window.height = WINDOW_MAX_HEIGHT;
}

void create_window(t_game *game, char *title)
{
    game->window.win = mlx_new_window(game->window.mlx, game->window.width, game->window.height, title);
}

void init_window(char *filename, t_game *game, char *title)
{
    init_mlx(game);
    read_map_size(filename, &game->map);
    calculate_window_size(game);
    create_window(game, title);
}

int validate_map_char(char c)
{
    if (c>='0' && c<='4')
        return (0);
    return (1);
}

int validate_map(t_map *map)
{
    int i;

    i = 0;
    while (i < map->width * map->height)
    {
        if (validate_map_char(map->tiles[i] + '0'))
            return (handle_error(ERROR_MAP_CHAR));
        i++;
    }
    return (0);
}

void    initialize_lut(t_game *game)
{
    game->lut[(unsigned char)'0'] = 1; 
    game->lut[(unsigned char)'1'] = 0; 
    game->lut[(unsigned char)'2'] = 2; 
    game->lut[(unsigned char)'3'] = 'E'; 
    game->lut[(unsigned char)'4'] = 'P'; 
}

void translate_map(t_game *game)
{
    int idx = 0;
    
    while (idx < NUM_TEXTURES ) 
    {
        game->map.tiles[idx] = game->lut[(unsigned char)game->map.tiles[idx]];
        idx++;
    }
}