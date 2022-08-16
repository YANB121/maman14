#include <errno.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "input_utils.h"

long string_to_number(char *nptr) {
    errno = 0;
    char *endptr = NULL;
    long number = strtol(nptr, &endptr, 10);

    if (nptr == endptr) {
        printf(" number : %ld  invalid  (no digits found, 0 returned)\n", number);
        return NULL;
    } else if (errno == ERANGE && number == LONG_MIN) {
        printf(" number : %ld  invalid  (underflow occurred)\n", number);
        return NULL;
    } else if (errno == ERANGE && number == LONG_MAX) {
        printf(" number : %ld  invalid  (overflow occurred)\n", number);
        return NULL;
    } else if (errno == EINVAL) {
        printf(" number : %ld  invalid  (base contains unsupported value)\n", number);
        return NULL;
    } else if (errno != 0 && number == 0) {
        printf(" number : %ld  invalid  (unspecified error occurred)\n", number);
        return NULL;
    } else if (number > INT_MAX || number < INT_MIN) {
        printf(" number : %ld  invalid, greater/lower  ()\n", number);
        return NULL;
    } else if (errno == 0 && nptr && !*endptr) {
        printf(" number : %ld    valid  (and represents all characters read)\n", number);
        return number;
    } else if (errno == 0 && nptr && *endptr != 0) {
        printf(" number : %ld    valid  (but additional characters remain)\n", number);
        return number;
    }


}


char *trim_commas(char *word) {
    word = word + 1;
    word[strlen(word) - 1] = '\0';
    return word;
}


bool is_int_array_contains(int *array, int value) {
    size_t array_length = sizeof(array) / sizeof(int);
    for (int i = 0; i < array_length; i++) {
        if (array[i] == value)
            return true;
    }
    return false;
}


char *convert_number_to_binary_string(int number) {
    char *str = malloc(12);
    str[11] = '\0';
    int i;
    for (i = 10; number > 0; i--) {
        str[i] = (number % 2) + '0';
        number = number / 2;
    }
    for (i = i; i >= 0; i--)
        str[i] = '0';
    return str;

}


char *trim_white_spaces(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char) *str)) str++;

    if (*str == 0)  // All spaces?
        return str;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char) *end)) end--;

    // Write new null terminator character
    end[1] = '\0';

    return str;
}
