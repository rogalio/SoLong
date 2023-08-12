#include "../include/so_long.h"

int move_up(t_game *game)
{
    int new_y;
    int new_x;

    new_x = game->player.x;
    new_y = game->player.y - 1;
    if (check_collision(game, new_x, new_y))
        return 1;
    update_position(game, new_x, new_y);
    return 0;
}

int move_down(t_game *game) {
    int new_y;
    int new_x;

    new_x = game->player.x;
    new_y = game->player.y + 1;
    if (check_collision(game, new_x, new_y))
        return 1;
    update_position(game, new_x, new_y);
    return 0;
}


int move_left(t_game *game) {
    int new_y;
    int new_x;

    new_x = game->player.x - 1;
    new_y = game->player.y;
    if (check_collision(game, new_x, new_y))
        return 1;
    update_position(game, new_x, new_y);
    return 0;
}

int move_right(t_game *game) {
    int new_y;
    int new_x;

    new_x = game->player.x + 1;
    new_y = game->player.y;
    if (check_collision(game, new_x, new_y))
        return 1;
    update_position(game, new_x, new_y);
    return 0;
}   

int handle_key_press(int keycode, t_game *game)
{
    if (keycode == 53)
        close_window(&game->window, &game->map);
    if (keycode == 126)
        move_up(game);
    if (keycode == 125)
        move_down(game);
    if (keycode == 123)
        move_left(game);
    if (keycode == 124)
        move_right(game);
    game->player.steps++;
    printf("steps taken: %d\n", game->player.steps);   
    return (0);
}