#ifndef MAMN14_ASSEMBLER_UTILS_H
#define MAMN14_ASSEMBLER_UTILS_H

#include "hashmap.h"

#define MAX_PROGRAM_LENGTH 1000


struct LabelSection {
    int dc;
    int ic;
    int instruction_array[MAX_PROGRAM_LENGTH];
    int data_array[MAX_PROGRAM_LENGTH];
    HashTable *label_table;
};

struct LabelEntry {
    int *type; // type of data/code
    int counter;// the relevant counter value (ic/dc)
};

struct LabelSection *initialize_label_section();

#endif //MAMN14_ASSEMBLER_UTILS_H
