#include "so_long.h"

int load_game_map(t_game *game, char *map_path)
{
    if (load_map(map_path, game) != 0)
        return (1);
    return (0);
}

int init_game(t_game *game, char **av, int ac, char **files)
{
    if (check_args(ac) != 0)
        return (1);
    init_window(game, WINDOW_WIDTH, WINDOW_HEIGHT , "so_long");
    if (load_game_map(game, av[1]) != 0)
        return (1);
    if (load_game_textures(game, files) != 0)
        return (1);
    if (draw_map(game) != 0)
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    t_game game;
    char *files[NUM_TEXTURES] =
    {
        "tiles/greystone.xpm",
        "tiles/empty.xpm", 
        "tiles/mossy.xpm", 
        "tiles/player.xpm", 
        "tiles/item.xpm"
    };

    // Initialise the game.
    if (init_game(&game, av, ac, files) != 0)
        return (1);
    
    // Setup the hooks.
    setup_hooks(&game);

    // Start the game loop.
    mlx_loop(game.window.mlx);
    return (0);

}