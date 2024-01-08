#include "../include/so_long.h"

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
    write(1, "Error: No exit found in map\n", 30);
    free(game->map.tiles);
    exit(1);
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
            game->items.collected = 0;
            game->player.steps = 0;
            return (0);
        }
        i++;
    }
    write(1, "Error: No player found in map\n", 30);
    free(game->map.tiles);
    exit(1);
}

int init_items(t_game *game)
{
    int i;

    i = 0;
    game->items.total = 0;
    while (i < game->map.width * game->map.height)
    {
        if (game->map.tiles[i] == TILE_ITEM)
            game->items.total++;
        i++;
    }
    return (0);
}

int init_game(t_game *game, char *map_path)
{
    init_window(map_path, game, GAME_TITLE);
    game->map.tiles = NULL;

    load_map(map_path, game);
    check_map(&game->map);
    init_player(game);
    init_items(game);
    init_exit(game);
    load_all_textures(game, NUM_TEXTURES);
    draw_map(game);

    return (0);
}
