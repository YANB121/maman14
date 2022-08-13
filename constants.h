
#ifndef MAMN14_CONSTANTS_H
#define MAMN14_CONSTANTS_H



struct HashTable *get_registers_map();

struct HashTable *get_data_instruction_map();

struct HashTable *get_opcode_and_decimal_map();

struct HashTable *get_additional_instruction_map();

void initialize_opcode_and_amount_of_operands_map();

void initialize_additional_instructions_map();

void initialize_constant_tables();

void initialize_opcode_table();

void initialize_registers_names_map();

void initialize_data_instructions_names_map();


#endif //MAMN14_CONSTANTS_H
