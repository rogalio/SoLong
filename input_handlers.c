#include "so_long.h"


int     ft_close(t_game *game)
{
    ft_free_map(game);
    ft_free_player(game);
    ft_free_collectibles(game);
    ft_free_exits(game);
    exit(0);
    return (0);
}

int     ft_exit(t_game *game)
{
    ft_free_map(game);
    ft_free_player(game);
    ft_free_collectibles(game);
    ft_free_exits(game);
    exit(0);
    return (0);
}



int     ft_key_press(int keycode, t_game *game)
{
    if (keycode == KEY_ESC)
        ft_close(game);
    else if (keycode == KEY_W)
        ft_move_up(game);
    else if (keycode == KEY_A)
        ft_move_left(game);
    else if (keycode == KEY_S)
        ft_move_down(game);
    else if (keycode == KEY_D)
        ft_move_right(game);
    return (0);
}