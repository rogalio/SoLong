#include "../include/so_long.h"

int open_map(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (handle_error(ERROR_OPEN, filename));
    return (fd);
}

int init_map(t_map *map, int width, int height)
{
    map->width = width;
    map->height = height;
    map->tiles = malloc(sizeof(int) * width * height);
    if (!map->tiles)
        return(handle_error(ERROR_ALLOC,"tiles\nfn : init_map"));
    return (0);
}

int read_map(int fd, t_map *map)
{
    char c;
    int tile_index = 0;
    ssize_t ret;

    while ((ret = read(fd, &c, 1)) > 0)
    {
        if (c == '\n') continue; // Ignore newline characters.

        // Convert character to t_tile and add to the map.
        if (c >= '0' && c <= '4') {
            map->tiles[tile_index] = (t_tile)(c - '0');
            tile_index++;
        }
        else 
            return (handle_error(ERROR_MAP, "Invalid character in map"));
    }
    if (ret == -1)
    {
        handle_error(ERROR_READ, fd);
        free(map->tiles);
        return (1);
    }
    return (0);
}

int load_map(char *filename,t_game *game)
{
    int fd;

    fd = open_map(filename);
    if (fd == -1)
        return (1);
    if (init_map(&game->map, MAP_WIDTH, MAP_HEIGHT) != 0)
    {
        close(fd);
        return (1);
    } 
    if (read_map(fd, &game->map) != 0)
    {
        close(fd);
        return (1);
    }
    close(fd);
    return (0);
}

int draw_map(t_game *game)
{
    int x;
    int y;
    int tile_index;

    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            tile_index = get_tile_index(&game->map, x, y);

            draw_texture(&game->window, &game->window.texture[game->map.tiles[tile_index]], x, y);
            printf("%d", game->map.tiles[tile_index]);
            x++;
        }
        printf("\n");
        y++;
    }
    
    return (0);
}