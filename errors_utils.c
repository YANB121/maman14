
#include "errors_utils.h"
#include "hashmap.h"

#define ERR_CODE_LABEL_ALREADY_IN_USE 1
#define ERR_CODE_LABEL_IS_INSTRUCTION 2
#define  ERR_CODE_LABEL_IS_OPERATION 3
#define ERR_CODE_LABEL_IS_REGISTER 4


struct HashTable *errors_map;


struct HashTable *get_errors_map() {
    return errors_map;

}

void initialize_errors_map() {
    errors_map = create_table(30);
    ht_insert(errors_map, ERR_CODE_LABEL_ALREADY_IN_USE, "the label is already in use.");
    ht_insert(errors_map, ERR_CODE_LABEL_IS_INSTRUCTION, "the label is a reserved instruction ");
    ht_insert(errors_map, ERR_CODE_LABEL_IS_OPERATION, "the label is a reserved operation");
    ht_insert(errors_map, ERR_CODE_LABEL_IS_REGISTER, "the label is a register name");

}


