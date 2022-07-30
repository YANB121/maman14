
#include "hashmap.h"
#include "string.h"
#include "assembler_iterations.h"
#include "constants.h"
#include "file_utils.h"

void test_map();

void test_arr();

void test_set_0();

void test();

int main(int size, char *argv[]) {
    initialize_constant_tables();

//    int i = 1;
//    for (i; i < size; i++) {
//        printf("%s", argv[i]);
//        span_macros(argv[i]);
//    }
//    char *str = malloc(sizeof(str));
//    char *delim = malloc(sizeof(str));
//    strcpy(str, "HELLO: .string \"AB:C\"");
//    strcpy(delim, " ");
//    str = strtok(str, delim);
//    printf("%s\n", str);
    //   printf("%s\n", &str[strlen(str)-1]);

//    if(strcmp( &str[strlen(str)-1] ,":"))
//        printf("true");
//    else
//        printf("false");


//    str = strtok(str, delim);
//    printf("%s\n",str);
//    str= strtok(str,":");
//    printf("%s",str);

//    char *str = malloc(sizeof(str));
//    strcpy(str, "HELLO: .string \"AB:C\"");
//    char* sym = get_symbol(str);
//    if(sym != NULL)
//        printf("%s",sym);
//    else
//        printf("get null");
//    char temp = *str;
//    printf("%c\n", temp);
//    printf("%s", str);

//    struct LineAndMetadata *lineAndMetadata = malloc(sizeof(struct LineAndMetadata));
//    char *line = malloc(sizeof(line));
//    lineAndMetadata->line = line;
//    strcpy(line, "mov");
//    printf("%s\n", lineAndMetadata->line);

//    char *word = get_data_instruction(lineAndMetadata);
//    char *word = get_opcode(lineAndMetadata);
//    if (word == NULL)
//        printf("null");
//    else
//        printf("%s\n", word);
//
//    printf("\n\n\n");
    char *word = malloc(1000);

    strcpy(word, "/home/ub-l/maman14.abcd");
//    char *file_word = basename(word);

//    printf("%s\n", file_word);
    printf("%s\n", word);
//    printf("%s\n", word);
    char *new_extension = get_name_with_new_file_extension(word, "eee", 4);
    if (new_extension != NULL) {
        printf("%s\n", new_extension);
    }
//    test_map();

    //test_arr();
//    test_set_0();

    return 0;
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
//    lineAndMetadata->errors_codes = calloc(10, sizeof(int));
    for (int i = 0; i < 10; i++)
        printf("%d\n", lineAndMetadata->errors_codes[i]);

    printf("---------------------------------\n");

    memset(lineAndMetadata->errors_codes, 0, ERROR_ARRAY_SIZE * sizeof(int));
    for (int i = 0; i < 10; i++)
        printf("%d\n", (lineAndMetadata->errors_codes)[i]);

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


