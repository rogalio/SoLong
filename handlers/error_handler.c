#include "../include/so_long.h"

const t_error errors[] = {
        {ERROR_ARG, "\nError\nWrong number of arguments.\nUsage: ./so_long <map.ber>"},
        {ERROR_FILE, "\nError\nCould not open file."},
        {ERROR_ALLOC, "\nError\nCould not allocate memory."},
        {ERROR_LOAD, "\nError\nCould not load."},
        {ERROR_READ, "\nError\nCould not read file."},
        {ERROR_INIT, "\nError\nCould not initialize window."},
        {ERROR_MAP, "\nError\nCould not load map."},
        {ERROR_TEXTURE, "\nError\nCould not load textures."},
        {ERROR_OPEN, "\nError\nCould not open file "},
        {ERROR_MAP_CHAR, "\nError\nInvalid character in map."},
        {0, ""}
    };

int handle_error(int error_code, ...) {
    va_list args;
    int i;

    i = 0;
    while (errors[i].code != 0)
    {
        if (errors[i].code == error_code)
        {
            printf("%s\n", errors[i].message);
            break;
        }
        i++;
    }
    va_start(args, error_code);
    printf("%s\n", va_arg(args, char *));
    va_end(args);

    //  free(map->tiles);
    // exit(error_code);

    return (1);
}
