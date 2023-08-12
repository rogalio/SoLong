#include "../include/so_long.h"


/**
 * close_window - Closes the minilibX window and exits the program.
 */
int close_window(t_window *data, t_map *map)
{
    free(map->tiles);
    mlx_destroy_image(data->mlx, data->texture[TILE_WALL].img);
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}

void collect_item(t_game *game)
{
    game->player.collected += 1;
    game->map.tiles[get_tile_index(&game->map, game->player.x, game->player.y)] = TILE_EMPTY;
    if (game->player.collected == 3)
        reveal_exit(game);
}



int reveal_exit(t_game *game)
{
    game->map.tiles[get_tile_index(&game->map, game->exit.x, game->exit.y)] = TILE_EXIT;
    draw_texture(&game->window, &game->window.texture[TILE_EXIT], game->exit.x, game->exit.y);
    return (0);
}


int check_collision(t_game *game, int new_x, int new_y)
{
    if (game->map.tiles[get_tile_index(&game->map, new_x, new_y)] == TILE_WALL)
        return 1;
    if (game->map.tiles[get_tile_index(&game->map, new_x, new_y)] == TILE_ITEM)
        collect_item(game);
    if (game->map.tiles[get_tile_index(&game->map, new_x, new_y)] == TILE_EXIT && check_all_items_gathered(game))
        close_window(&game->window, &game->map);
    
    return 0;
}

// check if player collected all items
int check_all_items_gathered(t_game *game)
{
    if (game->player.collected == 3)
        return 1;
    return 0;
}



void update_position(t_game *game, int new_x, int new_y)
{
    // Set the previous position to empty and clear the texture
    game->map.tiles[get_tile_index(&game->map, game->player.x, game->player.y)] = TILE_EMPTY;
    clear_texture(&game->window, game->player.x, game->player.y);

    // Update the player's position
    game->player.x = new_x;
    game->player.y = new_y;

    // Set the new position to player and redraw the texture
    game->map.tiles[get_tile_index(&game->map, game->player.x, game->player.y)] = TILE_PLAYER;
    redraw_texture(game, new_x, new_y);
}



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
 


