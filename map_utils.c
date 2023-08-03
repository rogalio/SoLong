#include "so_long.h"

int get_tile_index(t_map *map, int x, int y)
{
    return (y * map->width + x);
}

/*
int load_map(char *filename, t_map *map)
{
    int fd;
    char c;
    int tile_index;
    ssize_t ret;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        handle_error(ERROR_FILE);
        return (1);
    }

    // Initialiser les dimensions de la carte. 
    map->width = MAP_WIDTH;
    map->height = MAP_HEIGHT;

    // Allouer de la mémoire pour le tableau de tuiles.
    map->tiles = (int *)malloc(sizeof(int) * map->width * map->height);
    if (!map->tiles)
    {
        handle_error(ERROR_ALLOC_TILE);
        close(fd);
        return (1);
    }

    tile_index = 0;
    while ((ret = read(fd, &c, 1)) > 0)
    {
        if (c == '\n') continue; // Ignore newline characters.

        // Convert character to integer and add to the map.
        map->tiles[tile_index] = c - '0';
        tile_index++;
    }

    if (ret == -1)
    {
        handle_error(ERROR_READ_FILE);
        free(map->tiles);
        close(fd);
        return (1);
    }

    close(fd);
    return (0);
}
*/


int load_map(char *filename, t_map *map)
{
    int fd;
    char c;
    int tile_index;
    ssize_t ret;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        handle_error(ERROR_FILE);
        return (1);
    }

    // Initialiser les dimensions de la carte. 
    map->width = MAP_WIDTH;
    map->height = MAP_HEIGHT;

    // Allouer de la mémoire pour le tableau de tuiles.
    map->tiles = (int *)malloc(sizeof(int) * map->width * map->height);
    if (!map->tiles)
    {
        handle_error(ERROR_ALLOC_TILE);
        close(fd);
        return (1);
    }

    tile_index = 0;
    while ((ret = read(fd, &c, 1)) > 0)
    {
        if (c == '\n') continue; // Ignore newline characters.

        // Convert character to integer and add to the map.
        map->tiles[tile_index] = c - '0';
        tile_index++;
    }

    if (ret == -1)
    {
        handle_error(ERROR_READ_FILE);
        free(map->tiles);
        close(fd);
        return (1);
    }

    close(fd);
    return (0);
}

void draw_map(t_window *data, t_map *map, t_player *player, t_item *item)
{
    int x;
    int y;

    y = 0;
    while (y < map->height)
    {
        x = 0;
        while (x < map->width)
        {
            draw_tile(data, map, x, y);
            x++;
        }
        y++;
    }
    draw_player(data, player);
    draw_item(data, item);
}