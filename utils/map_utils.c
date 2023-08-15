#include "../include/so_long.h"

int open_map(char *filename)
{
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (handle_error(ERROR_OPEN, filename));
    return (fd);
}

int init_map(t_map *map)
{
    map->tiles = malloc(sizeof(t_tile) * map->width * map->height );
    if (map->tiles == NULL)
        return (handle_error(ERROR_ALLOC, "map->tiles"));
    
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
        // Convert character to integer and add to the map.
        map->tiles[tile_index] = c - '0';
        tile_index++;

    }

    if (ret == -1)
    {
        handle_error(ERROR_READ, fd);
        free(map->tiles);
        return (1);
    }

    return (0);

}

int read_map_size(char *filename, t_map *map) 
{
    char c;
    int current_line_width;
    int fd;

    map->width = 0;
    map->height = 0;
    current_line_width = 0;
    fd = open_map(filename);
    while (read(fd, &c, 1) > 0) {
        if (c == '\n') {
            if (map->width == 0)
                map->width = current_line_width;
            current_line_width = 0;
            map->height++;
        }
        else 
            current_line_width++; // Comptez les caractères pour déterminer la largeur de la ligne
    }
    
    // Si le fichier ne se termine pas par un '\n', ajoutez 1 à la hauteur
    if (current_line_width > 0 && current_line_width == map->width)
        map->height++;
    else if (current_line_width > 0 && current_line_width != map->width) 
        return (handle_error(ERROR_MAP, "Invalid map width"));
    // close the file and return 0 if success
    close(fd);
    return 0;
}


int load_map(char *filename, t_game *game) 
{
    int fd;
    
    fd = open_map(filename);
    if (init_map(&game->map) != 0)
        return (1);
    if (read_map(fd, &game->map) != 0)
        return (1);
    close(fd);

    return 0;
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