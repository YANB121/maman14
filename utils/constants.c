#include "hashmap.h"
#include "constants.h"

//const struct HashTable *registers = malloc(sizeof(char) * 10);
//const struct HashTable *dataInstructions;


void initialize_names_tables() {
    initialize_registers_names_map();
    initialize_data_instructions_names_map();
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






