#ifndef MAMN14_FILE_UTILS_H
#define MAMN14_FILE_UTILS_H

#include <stdio.h>

FILE *open_read_file_else_exit(char *);

FILE *open_write_file_else_exit(char *);

char *get_name_with_new_file_extension(char *original_path, char *new_extension, int original_extension_length);

#endif //MAMN14_FILE_UTILS_H
