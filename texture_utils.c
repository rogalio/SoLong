#include "so_long.h"

int load_texture(void *mlx_ptr, char *file, t_texture *tex)
{
    tex->img = mlx_xpm_file_to_image(mlx_ptr, file, &(tex->width), &(tex->line_length));
    if (!(tex->img))
    {
        handle_error(ERROR_LOAD_TEXTURE);
        return (1);
    }
    tex->addr = mlx_get_data_addr(tex->img, &(tex->bits_per_pixel), &(tex->line_length), &(tex->endian));
    return (0);
}

int load_all_textures(t_window *data, char **files, int num_textures)
{
    int i;

    i = 0;
    while (i < num_textures)
    {
        if (load_texture(data->mlx, files[i], &(data->texture[i])) != 0)
        {
            handle_error(ERROR_LOAD_TEXTURE);
            return (MLX_ERROR);
        }    
        i++;
    }
    return (0);
}



void draw_texture(t_window *data, t_texture *texture, int x, int y)
{
    mlx_put_image_to_window(data->mlx, data->win, texture->img, x, y);
}

void draw_tile(t_window *data, t_map *map, int x, int y)
{
    int tile_index;

    tile_index = get_tile_index(map, x, y);
    draw_texture(data, &(data->texture[map->tiles[tile_index]]), x * TILE_SIZE, y * TILE_SIZE);
}

void draw_player(t_window *data, t_player *player)
{
    draw_texture(data, &(player->texture), player->x, player->y);
}

void draw_item(t_window *data, t_item *item)
{
    if (!item->collected)
        draw_texture(data, &(item->texture), item->x, item->y);
}