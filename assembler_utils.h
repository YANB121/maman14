#ifndef MAMN14_ASSEMBLER_UTILS_H
#define MAMN14_ASSEMBLER_UTILS_H

#include "hashmap.h"

#define MAX_PROGRAM_LENGTH 1000
#define MAX_LABELS 100
#define MAX_STRING_SIZE 1000
#define ERROR_ARRAY_SIZE 20
#define  LINE_LENGTH 100
#define DATA_TYPE_LABEL 1
#define EXTERNAL_TYPE_LABEL 2
#define ENTRY_TYPE_LABEL 3
#define OPCODE_TYPE_LABEL 4

typedef struct InstructionEntry {
    int word[10];
} InstructionEntry;


struct LabelSection {
    int dc;
    int ic;
    char *instruction_array[MAX_PROGRAM_LENGTH];
    char *data_array[MAX_PROGRAM_LENGTH];
    HashTable *label_table;
    HashTable *entry_labels;
};

void write_memory_image_to_object_file(char *program_path, struct LabelSection *labelSection);

void write_entry_file(char *program_path, struct LabelSection *labelSection);

struct LabelSection *initialize_label_section();

char *ten_bits_binary_to_32_decimal(char *binary_num);

void write_external_file(char *program_path, struct LabelSection *labelSection);


#endif //MAMN14_ASSEMBLER_UTILS_H


