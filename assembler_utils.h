#ifndef MAMN14_ASSEMBLER_UTILS_H
#define MAMN14_ASSEMBLER_UTILS_H

#include "hashmap.h"

#define MAX_PROGRAM_LENGTH 1000
#define MAX_LABELS 100
#define MAX_STRING_SIZE 1000

typedef struct InstructionEntry {
    int word[10];
} InstructionEntry;


struct LabelSection {
    int dc;
    int ic;
    char *instruction_array[MAX_PROGRAM_LENGTH];
    int data_array[MAX_PROGRAM_LENGTH];
    HashTable *label_table;
};


struct LabelSection *initialize_label_section();

#endif //MAMN14_ASSEMBLER_UTILS_H
