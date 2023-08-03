#include "so_long.h"

// init player
void init_player(t_player *player, void *mlx_ptr, char *file, int init_x, int init_y)
{
    player->x = init_x;
    player->y = init_y;
    load_texture(mlx_ptr, file, &(player->texture));
}

// init item
void init_item(t_item *item, void *mlx_ptr, char *file, int init_x, int init_y)
{
    item->x = init_x;
    item->y = init_y;
    item->collected = 0;
    load_texture(mlx_ptr, file, &(item->texture));
}

int main(int ac, char **av)
{
    t_window data;
    char *files[NUM_TEXTURES] = {"tiles/greystone.xpm", "tiles/empty.xpm", "tiles/mossy.xpm", "tiles/player.xpm", "tiles/item.xpm"};
    t_map map;
    t_player player;
    t_item item;

    // Check for correct number of arguments.
    if (ac != 2)
    {
        handle_error(ERROR_ARG);
        return (ERROR_ARG);
    }

    // Initialize the minilibX.
    data.mlx = mlx_init();
    if (!data.mlx)
        return (MLX_ERROR);

    // Create a new window.
    data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "so_long");
    if (!data.win)
        return (MLX_ERROR);

    // Load textures.
    if (load_all_textures(&data, files, NUM_TEXTURES) != 0)
        return (MLX_ERROR);

    // Load map.
    if (load_map(av[1], &map) != 0)
        return (MLX_ERROR);

    // Initialize player.
    init_player(&player, data.mlx, "tiles/player.xpm", 100, 200);

    // Initialize item.
    init_item(&item, data.mlx, "tiles/item.xpm", 200, 300);
 
    // Draw map.
    draw_map(&data, &map, &player, &item);

    // Set up the hook functions.
    mlx_hook(data.win, 17, 0, close_window, &data);

    // Start the minilibX loop.
    mlx_loop(data.mlx);

    return (0);
}
