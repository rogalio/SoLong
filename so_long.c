#include "so_long.h"

/**
 * get_tile_index - Returns the index of a tile in the map array.
 * @x: X coordinate of the tile.
 * @y: Y coordinate of the tile.
 * Return: The index of the tile in the map array.
 */
int get_tile_index(int x, int y)
{
    return y * MAP_WIDTH + x;
}

/**
 * load_texture - Loads an image from a file and stores it in a texture structure,
 *                making it ready for graphical display.
 */
int load_texture(void *mlx_ptr, char *file, t_texture *tex)
{
    tex->img = mlx_xpm_file_to_image(mlx_ptr, file, &(tex->width), &(tex->line_length));
    if (!(tex->img))
        return (MLX_ERROR);
    tex->addr = mlx_get_data_addr(tex->img, &(tex->bits_per_pixel), &(tex->line_length), &(tex->endian));
    return (0);
}

/**
 * load_all_textures - Loads multiple textures from given files into the texture array.
 *
 * @data: Pointer to the data structure.
 * @files: Array of texture file paths.
 * @num_textures: Number of textures to load.
 *
 * Return: 0 if all textures are successfully loaded, otherwise return error code.
 */
int load_all_textures(t_window *data, char **files, int num_textures)
{
    int i;

    i = 0;
    while (i < num_textures)
    {
        if (load_texture(data->mlx, files[i], &(data->texture[i])) != 0)
        {
           printf("\nError\nCould not load texture => %s\n\n", files[i]);
           return (MLX_ERROR);
        }    
        i++;
    }
    return (0);
}

/**
 * draw_texture - Takes a loaded texture and displays it at a specified position 
 *                in the minilibX application window.
 */
void draw_texture(t_window *data, int texture_index, int x, int y)
{
    mlx_put_image_to_window(data->mlx, data->win, data->texture[texture_index].img, x, y);
}

/**
 * draw_map - Draws the map to the screen.
 */
void draw_map(t_window *data, t_map *map)
{
    int x;
    int y;
    int tile_index;
    int texture_index;

    y = 0;
    while (y < MAP_HEIGHT)
    {
        x = 0;
        while (x < MAP_WIDTH)
        {
            tile_index = get_tile_index(x, y);
            texture_index = map->tiles[tile_index];
            draw_texture(data, texture_index, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}

int main()
{
    t_window data;
    char *files[NUM_TEXTURES] = {"tiles/greystone.xpm", "tiles/bluestone.xpm", "tiles/mossy.xpm"};

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

    // Draw textures.
    t_map map = {
        .tiles = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            1, 2, 2, 2, 2, 2, 2, 2, 2, 1,
            1, 2, 0, 0, 0, 0, 0, 0, 2, 1,
            1, 2, 0, 0, 0, 0, 0, 0, 2, 1,
            1, 2, 0, 0, 0, 0, 0, 0, 2, 1,
            1, 2, 0, 0, 0, 0, 0, 0, 2, 1,
            1, 2, 0, 0, 0, 0, 0, 0, 2, 1,
            1, 2, 0, 0, 0, 0, 0, 0, 2, 1,
            1, 2, 2, 2, 2, 2, 2, 2, 2, 1,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        }
    };
    draw_map(&data, &map);

    // Start the minilibX loop.
    mlx_loop(data.mlx);

    return (0);
}
