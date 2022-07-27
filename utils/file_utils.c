
#include <stdlib.h>
#include <string.h>
//#include <libgen.h>
#include "file_utils.h"

#define  PATH_EXTENSION_MAX_SIZE 10

FILE *open_read_file_else_exit(char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        printf("input file not found");
        exit(1);
    } else
        return file;

}

FILE *open_write_file_else_exit(char *file_path) {
    FILE *file = fopen(file_path, "w");
    if (!file) {
        printf("input file not found");
        exit(1);
    } else
        return file;

}


char *get_name_with_new_file_extension(char *original_path, char *new_extension, int original_extension_length) {
    size_t n_length = (strlen(original_path) * sizeof(char)) + PATH_EXTENSION_MAX_SIZE;
    char *new_name = malloc(n_length);
    strcpy(new_name, original_path);



    //if the inserted extension length number greater than the path number, then return NULL.
    if (original_extension_length > strlen(original_path))
        return NULL;
    else {

        new_name[strlen(new_name) -
                 original_extension_length] = '\0'; //cut the last n characters from the string (the file extension)

        strncat(new_name, new_extension, strlen(new_extension)); //add the new extension to the file name
        return new_name;
    }
}

int find_extension_point(char *path) {
    for (int i = (strlen(path) - 1); i >= 0; i++) {
        if (path[i] == '.')
            return i;

    }

}
