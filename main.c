
#include "hashmap.h"
#include "preprocessor.h"
#include "string.h"

int main(int size, char *argv[]) {

    int i = 1;
    for (i; i < size; i++) {
        printf("%s", argv[i]);
        span_macros(argv[i]);
    }



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