#include "hashmap.h"
#include "constants.h"
#include <stdbool.h>

struct HashTable *registers;
struct HashTable *dataInstructions;
struct HashTable *opcodeAndDecimal;
struct HashTable *additionalInstructions;
struct HashTable *opcodeAndAmountOfOperands;
struct HashTable *validSourceAddressingMap;
struct HashTable *validDestAddressingMap;

struct HashTable *get_valid_source_addressing_map() {
    return validSourceAddressingMap;
}

struct HashTable *get_valid_dest_addressing_map() {
    return validDestAddressingMap;
}


struct HashTable *get_registers_map() {
    return registers;
}

struct HashTable *get_data_instruction_map() {
    return dataInstructions;
}

struct HashTable *get_opcode_and_decimal_map() {
    return opcodeAndDecimal;
}

struct HashTable *get_opcode_and_amount_of_operands_map() {
    return opcodeAndAmountOfOperands;
}


struct HashTable *get_additional_instruction_map() {
    return additionalInstructions;
}


void initialize_constant_tables() {
    initialize_registers_names_map();
    initialize_data_instructions_names_map();
    initialize_opcode_table();
    initialize_additional_instructions_map();
    initialize_opcode_and_amount_of_operands_map();
    initialize_valid_source_addressing_method_map();
    initialize_valid_dest_addressing_method_map();
}


void initialize_valid_source_addressing_method_map() {
    validSourceAddressingMap = create_table(16);

    ht_insert(validSourceAddressingMap, "mov", "0123");
    ht_insert(validSourceAddressingMap, "cmp", "0123");
    ht_insert(validSourceAddressingMap, "add", "0123");
    ht_insert(validSourceAddressingMap, "sub", "0123");
    ht_insert(validSourceAddressingMap, "not", "123");
    ht_insert(validSourceAddressingMap, "clr", "123");
    ht_insert(validSourceAddressingMap, "lea", "12");
    ht_insert(validSourceAddressingMap, "inc", "123");
    ht_insert(validSourceAddressingMap, "dec", "123");
    ht_insert(validSourceAddressingMap, "jmp", "123");
    ht_insert(validSourceAddressingMap, "bne", "123");
    ht_insert(validSourceAddressingMap, "get", "123");
    ht_insert(validSourceAddressingMap, "prn", "0123");
    ht_insert(validSourceAddressingMap, "jsr", "123");
    ht_insert(validSourceAddressingMap, "rts", NULL);
    ht_insert(validSourceAddressingMap, "hlt", NULL);
}

void initialize_valid_dest_addressing_method_map() {
    validDestAddressingMap = create_table(16);

    ht_insert(validDestAddressingMap, "mov", "12");
    ht_insert(validDestAddressingMap, "cmp", "0123");
    ht_insert(validDestAddressingMap, "add", "123");
    ht_insert(validDestAddressingMap, "sub", "123");
    ht_insert(validDestAddressingMap, "not", "123");
    ht_insert(validDestAddressingMap, "clr", "123");
    ht_insert(validDestAddressingMap, "lea", "123");
    ht_insert(validDestAddressingMap, "inc", "123");
    ht_insert(validDestAddressingMap, "dec", "123");
    ht_insert(validDestAddressingMap, "jmp", "123");
    ht_insert(validDestAddressingMap, "bne", "123");
    ht_insert(validDestAddressingMap, "get", "123");
    ht_insert(validDestAddressingMap, "prn", "0123");
    ht_insert(validDestAddressingMap, "jsr", "123");
    ht_insert(validDestAddressingMap, "rts", NULL);
    ht_insert(validDestAddressingMap, "hlt", NULL);
}


void initialize_opcode_and_amount_of_operands_map() {
    opcodeAndAmountOfOperands = create_table(16);
    ht_insert(opcodeAndAmountOfOperands, "mov", "2");
    ht_insert(opcodeAndAmountOfOperands, "cmp", "2");
    ht_insert(opcodeAndAmountOfOperands, "add", "2");
    ht_insert(opcodeAndAmountOfOperands, "sub", "2");
    ht_insert(opcodeAndAmountOfOperands, "not", "1");
    ht_insert(opcodeAndAmountOfOperands, "clr", "1");
    ht_insert(opcodeAndAmountOfOperands, "lea", "2");
    ht_insert(opcodeAndAmountOfOperands, "inc", "1");
    ht_insert(opcodeAndAmountOfOperands, "dec", "1");
    ht_insert(opcodeAndAmountOfOperands, "jmp", "1");
    ht_insert(opcodeAndAmountOfOperands, "bne", "1");
    ht_insert(opcodeAndAmountOfOperands, "get", "1");
    ht_insert(opcodeAndAmountOfOperands, "prn", "1");
    ht_insert(opcodeAndAmountOfOperands, "jsr", "1");
    ht_insert(opcodeAndAmountOfOperands, "rts", "0");
    ht_insert(opcodeAndAmountOfOperands, "hlt", "0");

}


void initialize_registers_names_map() {
    registers = create_table(20);
    ht_insert(registers, "r0", true);
    ht_insert(registers, "r1", true);
    ht_insert(registers, "r2", true);
    ht_insert(registers, "r3", true);
    ht_insert(registers, "r4", true);
    ht_insert(registers, "r5", true);
    ht_insert(registers, "r6", true);
    ht_insert(registers, "r7", true);
}

void initialize_data_instructions_names_map() {
    dataInstructions = create_table(20);
    ht_insert(dataInstructions, ".data", 1);
    ht_insert(dataInstructions, ".string", 2);
    ht_insert(dataInstructions, ".struct", 3);
    ht_insert(dataInstructions, ".entry", 4);
    ht_insert(dataInstructions, ".external", 5);
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
    ht_insert(additionalInstructions, ".external", true);
    ht_insert(additionalInstructions, ".entry", true);


}



