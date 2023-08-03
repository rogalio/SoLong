#include "so_long.h"


void handle_error(int error_code) {
    switch(error_code) {
        case ERROR_ARG:
            printf("\nError\n: Incorrect number of arguments.\n\n");
            break;
        case ERROR_FILE:
            printf("\nError\n: Could not open file.\n\n");
            break;
        case ERROR_ALLOC_TILE:
            printf("\nError\n: Could not allocate memory for tiles.\n\n");
            break;
        case ERROR_LOAD_TILE:
            printf("\nError\n: Could not load tile.\n\n");
            break;
        case ERROR_READ_FILE:
            printf("\nError\n: Could not read file.\n\n");
            break;
        case ERROR_LOAD_TEXTURE:
            printf("\nError\n: Could not load texture.\n\n");
            break;
    }
}