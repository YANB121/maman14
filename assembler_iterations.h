
#ifndef MAMN14_ASSEMBLER_ITERATIONS_H
#define MAMN14_ASSEMBLER_ITERATIONS_H

#include <stdio.h>
#include "utils/hashmap.h"
#include "utils/assembler_utils.h"

#define ERROR_ARRAY_SIZE 10

typedef struct LineAndMetadata {
    int line_number;
    char *line;
    int errors_codes[ERROR_ARRAY_SIZE];
    int is_error_occurred;
    int is_contains_label;
};

char *get_opcode(struct LineAndMetadata *);

int first_iteration(char *);

void second_iteration(char *);

struct LineAndMetadata *initialize_line_and_metadata(char *line, int line_number);

char *get_symbol(char *line);

char *get_instruction(struct LineAndMetadata *);

void *handle_data_instruction(char *line, int contains_symbol, struct SymbolsSection *symbolsSection);

void *handle_data_type_without_symbol(char *line);

void *handle_data_type_with_symbol(char *line);

void *handle_operation(char *line, int contains_symbol, struct SymbolsSection *symbolsSection);

char *validate_instruction(char *instruction_word);

#endif //MAMN14_ASSEMBLER_ITERATIONS_H
