
#include "errors_utils.h"
#include "hashmap.h"

//#define ERR_CODE_LABEL_ALREADY_IN_USE 1
//#define ERR_CODE_LABEL_IS_INSTRUCTION 2
//#define  ERR_CODE_LABEL_IS_OPERATION 3
//#define ERR_CODE_LABEL_IS_REGISTER 4
//#define ERR_CODE_INVALID_DATA_TYPE 5

struct HashTable *errors_map;


struct HashTable *get_errors_map() {
    return errors_map;

}

void initialize_errors_map() {
    errors_map = create_table(30);
    ht_insert(errors_map, ERR_CODE_LABEL_ALREADY_IN_USE, "the label is already in use.");
    ht_insert(errors_map, ERR_CODE_LABEL_IS_INSTRUCTION, "the label is a reserved instruction_type ");
    ht_insert(errors_map, ERR_CODE_LABEL_IS_OPERATION, "the label is a reserved operation");
    ht_insert(errors_map, ERR_CODE_LABEL_IS_REGISTER, "the label is a register name");
    ht_insert(errors_map, ERR_CODE_INVALID_DATA_TYPE, "the data type is invalid, only integers allowed");
    ht_insert(errors_map, ERR_CODE_INVALID_STRING_TYPE, "the string type is invalid");
    ht_insert(errors_map, ERR_CODE_TOO_MANY_ARGUMENTS, "line contains too many arguments");
    ht_insert(errors_map, ERR_CODE_INVALID_ARGUMENTS, "invalid arguments error");
    ht_insert(errors_map, ERR_CODE_INVALID_OPERANDS, "invalid operands error");
}


