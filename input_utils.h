//
// Created by Lidar on 12/08/2022.
//

#ifndef MAMN14_INPUT_UTILS_H
#define MAMN14_INPUT_UTILS_H

#include <stdbool.h>

long string_to_number(char *);

char *trim_commas(char *);

bool is_int_array_contains(int *array, int value);

char* convert_number_to_binary_string(int number);


#endif //MAMN14_INPUT_UTILS_H
