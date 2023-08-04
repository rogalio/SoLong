#include "../include/so_long.h"



int check_args(int ac)
{
    if (ac != 2)
        return (handle_error(ERROR_ARG));
    return (0);
}

void setup_hooks(t_game *game)
{
    mlx_hook(game->window.win, 17, 0, close_window, game);
}

int get_tile_index(t_map *map, int x, int y)
{
    return (y * map->width + x);
}

void init_window(t_game *game, int width, int height, char *title)
{
    game->window.mlx = mlx_init();
    game->window.win = mlx_new_window(game->window.mlx, width, height, title);
}