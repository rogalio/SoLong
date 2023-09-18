#include "../include/so_long.h"



int load_all_textures(t_game *game, int num_files)
{
    int i;
    static char *files[NUM_TEXTURES] =
    {
        "tiles/wallpackman.xpm",
        "tiles/emptypackman.xpm",
         "tiles/itempackman.xpm",
        "tiles/exitpackman.xpm",
        "tiles/playerpackman.xpm",
    };
    i = 0;
    while (i < num_files)
    {
        if (load_texture(game->window.mlx, files[i], &game->window.texture[i]) != 0)
        {
            printf("Error: Could not load texture %s\n", files[i]);
            free(game->map.tiles);
            exit(1);
        }
        i++;
    }
    return (0);
}


int load_texture(void *mlx_ptr, char *file, t_texture *tex)
{
    tex->img = mlx_xpm_file_to_image(mlx_ptr, file, &tex->width, &tex->line_length);
    if (tex->img == NULL)
    {
        printf("Error: Could not load texture %s\n", file);
        return (1);
    }
    tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel, &tex->line_length, &tex->endian);
    return (0);
}


void draw_texture(t_window *data, t_texture *texture, int x, int y)
{
    mlx_put_image_to_window(data->mlx, data->win, texture->img, x * TILE_SIZE, y * TILE_SIZE);
}

void clear_texture(t_window *data, int x, int y)
{
    draw_texture(data, &data->texture[TILE_EMPTY], x, y);
}

void redraw_texture(t_game *game, int x, int y)
{
    t_map *map = &game->map;

    if (map->tiles[get_tile_index(map, x, y)] == TILE_WALL)
        draw_texture(&game->window, &game->window.texture[TILE_WALL], x, y);
    else if (map->tiles[get_tile_index(map, x, y)] == TILE_EMPTY)
        draw_texture(&game->window, &game->window.texture[TILE_EMPTY], x, y);
    else if (map->tiles[get_tile_index(map, x, y)] == TILE_ITEM)
        draw_texture(&game->window, &game->window.texture[TILE_ITEM], x, y);
    else if (map->tiles[get_tile_index(map, x, y)] == TILE_EXIT)
        draw_texture(&game->window, &game->window.texture[TILE_EXIT], x, y);
    else if (map->tiles[get_tile_index(map, x, y)] == TILE_PLAYER)
        draw_texture(&game->window, &game->window.texture[TILE_PLAYER], x, y);
}
