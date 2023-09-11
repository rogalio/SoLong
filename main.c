#include "./include/so_long.h"


int main(int ac, char **av)
{
    t_game game;

    char *files[NUM_TEXTURES] =
    { 
        "tiles/wallpackman.xpm",
        "tiles/emptypackman.xpm",
         "tiles/itempackman.xpm",
        "tiles/exitpackman.xpm", 
        "tiles/playerpackman.xpm", 
    };
    
    if (validate_arguments(ac) != 0)
        return (1);

    if (init_game(&game, av[1], files) != 0)
        return (1);
    
    setup_hooks(&game);
    mlx_loop(game.window.mlx);

    return (0);
}

