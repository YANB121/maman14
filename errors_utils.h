

#ifndef MAMN14_ERRORS_UTILS_H
#define MAMN14_ERRORS_UTILS_H


#define ERR_CODE_LABEL_ALREADY_IN_USE "A"
#define ERR_CODE_LABEL_IS_INSTRUCTION "B"
#define  ERR_CODE_LABEL_IS_OPERATION "C"
#define ERR_CODE_LABEL_IS_REGISTER "D"
#define ERR_CODE_INVALID_DATA_TYPE "E"
#define ERR_CODE_INVALID_STRING_TYPE "F"
#define ERR_CODE_TOO_MANY_ARGUMENTS "G"
#define ERR_CODE_INVALID_ARGUMENTS "H"
#define ERR_CODE_INVALID_OPERANDS "I"
#define ERR_CODE_INVALID_OPERANDS_AMOUNT "J"
#define ERR_CODE_INVALID_OPERANDS_SYNTAX "K"
#define ERR_CODE_INVALID_OPERANDS_TYPE "L"


struct HashTable *get_errors_map();


void initialize_errors_map();


#endif //MAMN14_ERRORS_UTILS_H
