#include "so_long.h"

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
