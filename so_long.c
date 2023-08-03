#include "so_long.h"





int main(int ac, char **av)
{
    t_window data;
    char *files[NUM_TEXTURES] = {"tiles/greystone.xpm", "tiles/bluestone.xpm", "tiles/mossy.xpm"};
    t_map map;

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

    // Draw map.
    draw_map(&data, &map);

    // Set up the hook functions.
    mlx_hook(data.win, 17, 0, close_window, &data);

    // Start the minilibX loop.
    mlx_loop(data.mlx);

    return (0);
}
