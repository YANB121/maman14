#include "hashmap.h"
#include "constants.h"

struct HashTable *registers;
struct HashTable *dataInstructions;
struct HashTable *opcodeAndDecimal;
struct HashTable *additionalInstructions;

struct HashTable *get_registers_map() {
    return registers;
}

struct HashTable *get_data_instruction_map() {
    return dataInstructions;
}

struct HashTable *get_opcode_and_decimal_map() {
    return opcodeAndDecimal;
}

struct HashTable *get_additional_instruction_map() {
    return additionalInstructions;
}


void initialize_constant_tables() {
    initialize_registers_names_map();
    initialize_data_instructions_names_map();
    initialize_opcode_table();
    initialize_additional_instructions_map();
}


void initialize_registers_names_map() {
    registers = create_table(20);
    ht_insert(registers, "r0", "true");
    ht_insert(registers, "r1", "true");
    ht_insert(registers, "r2", "true");
    ht_insert(registers, "r3", "true");
    ht_insert(registers, "r4", "true");
    ht_insert(registers, "r5", "true");
    ht_insert(registers, "r6", "true");
    ht_insert(registers, "r7", "true");
}

void initialize_data_instructions_names_map() {
    dataInstructions = create_table(20);
    ht_insert(dataInstructions, ".data", "true");
    ht_insert(dataInstructions, ".string", "true");
    ht_insert(dataInstructions, ".struct", "true");
}

void initialize_opcode_table() {
    opcodeAndDecimal = create_table(16);
    ht_insert(opcodeAndDecimal, "mov", "0");
    ht_insert(opcodeAndDecimal, "cmp", "1");
    ht_insert(opcodeAndDecimal, "add", "2");
    ht_insert(opcodeAndDecimal, "sub", "3");
    ht_insert(opcodeAndDecimal, "not", "4");
    ht_insert(opcodeAndDecimal, "clr", "5");
    ht_insert(opcodeAndDecimal, "lea", "6");
    ht_insert(opcodeAndDecimal, "inc", "7");
    ht_insert(opcodeAndDecimal, "dec", "8");
    ht_insert(opcodeAndDecimal, "jmp", "9");
    ht_insert(opcodeAndDecimal, "bne", "10");
    ht_insert(opcodeAndDecimal, "get", "11");
    ht_insert(opcodeAndDecimal, "prn", "12");
    ht_insert(opcodeAndDecimal, "jsr", "13");
    ht_insert(opcodeAndDecimal, "rts", "14");
    ht_insert(opcodeAndDecimal, "hlt", "15");


}

void initialize_additional_instructions_map() {
    additionalInstructions = create_table(20);
    ht_insert(additionalInstructions, ".external", "true");
    ht_insert(additionalInstructions, ".entry", "true");


}



