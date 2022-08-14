
#include "hashmap.h"
#include "string.h"
#include "assembler_iterations.h"
#include "constants.h"
#include "input_utils.h"
#include  <stdlib.h>
#include <stdio.h>

void test_map();

void test_arr();

void test_set_0();

void test();

void print_binary(int num);

int main(int size, char *argv[]) {
    initialize_constant_tables();

//    char *line = malloc(sizeof(char) * 1000);
//    strcpy(line, "string,  string, strong");
//    printf("%s\n", line);
//    char *word = strtok(line, ",");
//    word = strtok(NULL, " ");
//    word = strtok(NULL, ",");
////    word = strtok(NULL, ",");
////    word = strtok(NULL, ",");
//    if (word == NULL)
//        printf("NULL\n");
//    else
//        printf("%s\n", word);
//    free(line);

//    char *line2 = malloc(sizeof(char) * 1000);
//    strcpy(line2, "string,string,strong");
//
//    char w = line2[0];
//    char l = line2[strlen(line2)-1];
//    int asc = w;
//    printf("%d\n",asc);
//    printf("%s\n",line2+1);

//    struct LabelSection *labelSection = malloc(sizeof(struct LabelSection));
//    labelSection->ic =10;
//    printf("%d\n",labelSection->ic);
//    int temp_ic =labelSection->ic;
//    printf("%d\n",temp_ic);
//    temp_ic = 36;
//    printf("%d\n",temp_ic);
//    printf("%d\n",labelSection->ic);

    int a = 10;
    char b= a +'0';
    printf("%d\n",a);
    printf("%c\n",b);

}

void print_binary(int num) {
    int a[10];
    int i = 0;
    for (i; num > 0; i++) {
        a[i] = num % 2;
        num = num / 2;
    }
    printf("\nBinary of Given Number is=");
    i = i - 1;
    for (i; i >= 0; i--) {
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




