#include "./include/so_long.h"


int main(int ac, char **av)
{
    t_game game;

    validate_arguments(ac);
    initialize_lut(&game); 
    init_game(&game, av[1]);
    translate_map(&game);
    setup_hooks(&game);
    mlx_loop(game.window.mlx);
    close_game(&game);

    return (0);
}