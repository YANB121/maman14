
#ifndef MAMN14_CONSTANTS_H
#define MAMN14_CONSTANTS_H


#define IMMEDIATE_ADDRESSING_OPERAND 1
#define DIRECT_ADDRESSING_OPERAND 2
#define DIRECT_OFFSET_ADDRESSING_OPERAND 3
#define REGISTER_ADDRESSING_OPERAND 4


#define DATA_TYPE 1
#define STRING_TYPE 2
#define STRUCT_TYPE 3
#define ENTRY_TYPE 4
#define EXTERNAL_TYPE 5


struct HashTable *get_valid_source_addressing_map();

struct HashTable *get_valid_dest_addressing_map();

struct HashTable *get_registers_map();

struct HashTable *get_data_instruction_map();

struct HashTable *get_opcode_and_decimal_map();

struct HashTable *get_opcode_and_amount_of_operands_map();

struct HashTable *get_additional_instruction_map();

void initialize_opcode_and_amount_of_operands_map();

void initialize_additional_instructions_map();

void initialize_constant_tables();

void initialize_opcode_table();

void initialize_registers_names_map();

void initialize_data_instructions_names_map();

void initialize_valid_source_addressing_method_map();

void initialize_valid_dest_addressing_method_map();

#endif //MAMN14_CONSTANTS_H
