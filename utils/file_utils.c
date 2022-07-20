
#include <stdlib.h>
#include "file_utils.h"

FILE *open_read_file_else_exit(char *file_path) {
    FILE *file = fopen(file_path,"r");
    if (!file) {
        printf("input file not found");
        exit(1);
    } else
        return file;

}

FILE *open_write_file_else_exit(char *file_path) {
    FILE *file = fopen(file_path,"w");
    if (!file) {
        printf("input file not found");
        exit(1);
    } else
        return file;

}

