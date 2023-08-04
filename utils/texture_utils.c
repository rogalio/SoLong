#include "../include/so_long.h"


int load_texture(void *mlx_ptr, char *file, t_texture *tex)
{
    tex->img = mlx_xpm_file_to_image(mlx_ptr, file, &(tex->width), &(tex->line_length));
    if (!(tex->img))
        return (handle_error(ERROR_LOAD, "texture"));
    tex->addr = mlx_get_data_addr(tex->img, &(tex->bits_per_pixel), &(tex->line_length), &(tex->endian));
    return (0);
}

int load_all_textures(t_game *game, char **files, int num_files)
{
    int i;

    i = 0;
    while (i < num_files)
    {
        if (load_texture(game->window.mlx, files[i], &(game->window.texture[i])) != 0)
            return (1);
        i++;
    }
    return (0);
}

int load_game_textures(t_game *game, char **files)
{
    if (load_all_textures(game, files, NUM_TEXTURES) != 0)
        return (1);
    return (0);
}

void draw_element(t_window *data, t_texture *texture, int x, int y)
{
    mlx_put_image_to_window(data->mlx, data->win, texture->img, x * TILE_SIZE, y * TILE_SIZE);
}