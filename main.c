#include "./include/so_long.h"

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