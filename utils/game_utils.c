#include "../include/so_long.h"

int load_game_map(t_game *game, char *map_path)
{
    if (load_map(map_path, game) != 0)
        return (1);
    return (0);
}


int hide_exit(t_game *game)
{
    game->map.tiles[get_tile_index(&game->map, game->exit.x, game->exit.y)] = TILE_EMPTY;
    return (0);
}

int init_exit(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map.width * game->map.height)
    {
        if (game->map.tiles[i] == TILE_EXIT)
        {
            game->exit.x = i % game->map.width;
            game->exit.y = i / game->map.width;
            hide_exit(game);
            return (0);
        }
        i++;
    }
    return (handle_error(ERROR_MAP, "No exit in map"));
}

int init_player(t_game *game)
{
    int i;

    i = 0;
    while (i < game->map.width * game->map.height)
    {
        if (game->map.tiles[i] == TILE_PLAYER)
        {
            game->player.x = i % game->map.width;
            game->player.y = i / game->map.width;
            game->player.collected = 0;
            game->player.steps = 0;
            return (0);
        }
        i++;
    }
    return (handle_error(ERROR_MAP, "No player in map"));
}

int init_game(t_game *game, char **av, int ac, char **files)
{
   if (check_args(ac) != 0)
        return (1);
    init_window(game, WINDOW_WIDTH, WINDOW_HEIGHT , "so_long");
    if (load_game_map(game, av[1]) != 0)
        return (1);
   if (init_player(game) != 0)
      return (1);
    if (init_exit(game) != 0)
       return (1);
    if (load_game_textures(game, files) != 0)
        return (1);
    if (draw_map(game) != 0)
        return (1);
    return (0);
}
