
#ifndef MAMN14_CONSTANTS_H
#define MAMN14_CONSTANTS_H


struct HashTable *registers;
struct HashTable *dataInstructions;
struct HashTable *opcodeAndDecimal;
struct HashTable *additionalInstructions;



void initialize_additional_instructions_map();
void initialize_constant_tables();
void initialize_opcode_table();
void initialize_registers_names_map();
void initialize_data_instructions_names_map();



#endif //MAMN14_CONSTANTS_H
