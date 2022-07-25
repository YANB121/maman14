
#ifndef MAMN14_ASSEMBLER_ITERATIONS_H
#define MAMN14_ASSEMBLER_ITERATIONS_H

#include <stdio.h>
#include "utils/hashmap.h"
#include "utils/assembler_utils.h"

#define ERROR_ARRAY_SIZE 10
#define  LINE_LENGTH 100

typedef struct LineAndMetadata {
    int line_number;
    char *line;
    int errors_codes[ERROR_ARRAY_SIZE];
//    int *errors_codes;
    int is_error_occurred;
    int is_contains_label;
    char *label;
};

void *validate_label(struct LineAndMetadata *, HashTable *);


int is_empty_or_comment(char *);

void insert_data_label_into_table(struct LabelSection *, struct LineAndMetadata *);

char *get_opcode(struct LineAndMetadata *);

int first_iteration(char *);

void second_iteration(char *);

struct LineAndMetadata *initialize_line_and_metadata(char *line, int line_number);

char *get_symbol(char *line);

char *get_data_instruction(struct LineAndMetadata *lineAndMetadata);

void *handle_data_instruction(struct LineAndMetadata *, struct LabelSection *);

void *handle_data_type_without_symbol(struct LineAndMetadata *);

void *handle_data_type_with_label(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection);

void *handle_operation(struct LineAndMetadata *, struct LabelSection *symbolsSection);

char *validate_instruction(char *instruction_word);

#endif //MAMN14_ASSEMBLER_ITERATIONS_H
