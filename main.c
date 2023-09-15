#include "./include/so_long.h"


int main(int ac, char **av)
{
    t_game game;

    if (validate_arguments(ac) != 0)
        return (1);

    if (init_game(&game, av[1]) != 0)
        return (1);

    setup_hooks(&game);

    mlx_loop(game.window.mlx);

    close_game(&game);

    return (0);
}