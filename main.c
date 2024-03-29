
#include "hashmap.h"
#include <string.h>
#include "assembler_iterations.h"
#include "constants.h"
#include "input_utils.h"
#include "preprocessor.h"
#include  <stdlib.h>
#include <stdio.h>
#include "errors_utils.h"

void test_map();

void test_arr();

void test_set_0();

void test();

void print_binary(int num);

int main(int size, char *argv[]) {
    initialize_constant_tables();
    initialize_errors_map();
    if (size < 2) {
        printf("please pass at least 1 file name as argument");
        exit(1);
    }

    for (int i = 1; i < size; i++) {
//    char *path = malloc(30);
//    strcpy(path,"program_code.as");
        char *path = argv[i];
        span_macros(path);

        path[strlen(path) - 3] = '\0';
        char a[3] = ".am";
        strncat(path, a, 3); //add .am extension to the file name

        struct LabelSection *labelSection = initialize_label_section();

        first_iteration(path, labelSection);
        printf("\n");
        print_table(labelSection->label_table);

        second_iteration(path, labelSection);

        write_memory_image_to_object_file(path, labelSection);
        write_external_file(path, labelSection);
        write_entry_file(path, labelSection);
    }
}

void print_binary(int num) {
    int a[11];
    int i = 0;
    for (i; num > 0; i++) {
        a[i] = num % 2;
        num = num / 2;
    }
    printf("\nBinary of Given Number is=");
    i = i - 1;
    for (i = i; i >= 0; i--) {
        printf("%d", a[i]);
    }

}


void test() {
    int *counter_and_type = calloc(2, sizeof(int));
    counter_and_type[0] = 6;
    counter_and_type[1] = 7;
    printf("0- %d,1- %d", counter_and_type[0], counter_and_type[1]);
//    ht_insert(labelSection->label_table, lineAndMetadata->label, counter_and_type);


}


void test_find_extension_point() {
    char *word = malloc(100);
    strcpy(word, "path.12");
//    int pos = find_extension_point(word);
}

void test_set_0() {
    struct LineAndMetadata *lineAndMetadata = malloc(sizeof(struct LineAndMetadata));
//    lineAndMetadata->arr_errors_codes = calloc(10, sizeof(int));
    for (int i = 0; i < 10; i++)
        printf("%d\n", lineAndMetadata->arr_errors_codes[i]);

    printf("---------------------------------\n");

    memset(lineAndMetadata->arr_errors_codes, 0, ERROR_ARRAY_SIZE * sizeof(int));
    for (int i = 0; i < 10; i++)
        printf("%d\n", (lineAndMetadata->arr_errors_codes)[i]);

}


void test_arr() {
    int arr[10];
    for (int i = 0; i < 10; i++)
        printf("%d\n", arr[i]);
}

void test_map() {
    int SIZE = 10;
    printf("%d\n", SIZE);
    HashTable *ht = create_table(SIZE);

    ht_insert(ht, "1", "First address");
    ht_insert(ht, "2", "Second address");
    ht_insert(ht, "3", "Third address");

    print_search(ht, "1");
    print_search(ht, "2");
    print_search(ht, "3");

    print_table(ht);
    free_table(ht);
}




