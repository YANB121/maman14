
#include "utils/hashmap.h"
#include "preprocessor.h"
#include "string.h"
#include "assembler_iterations.h"

int main(int size, char *argv[]) {

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

    char *str = malloc(sizeof(str));
    strcpy(str, "HELLO: .string \"AB:C\"");
//    char* sym = get_symbol(str);
//    if(sym != NULL)
//        printf("%s",sym);
//    else
//        printf("get null");
    char temp = *str;
    printf("%c\n", temp);
    printf("%s", str);
    return 0;
}





/*void test(){

    int SIZE=10;
    printf("%d\n",SIZE);
    HashTable* ht = create_table(SIZE);
    ht_insert(ht, "1", "First address");
    ht_insert(ht, "2", "Second address");
    ht_insert(ht, "3", "Third address");

    print_search(ht, "1");
    print_search(ht, "2");
    print_search(ht, "3");

    print_table(ht);
    free_table(ht); */