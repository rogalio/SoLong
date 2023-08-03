#include "so_long.h"


/**
 * close_window - Closes the minilibX window and exits the program.
 */
int close_window(t_window *data, t_map *map)
{
    free(map->tiles);
    printf("Exiting program...\n");
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}


/**

int handle_key_press(int keycode, t_window *data, t_map *map)
{
    printf("keycode: %d\n", keycode);
    if (keycode == 65307)
        close_window(data, map);
    return (0);
}
 */

/**

int handle_key_release(int keycode, t_window *data, t_map *map)
{
    printf("keycode: %d\n", keycode);
    return (0);
}
 */


