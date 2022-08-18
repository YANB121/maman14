
#ifndef MAMN14_ASSEMBLER_ITERATIONS_H
#define MAMN14_ASSEMBLER_ITERATIONS_H

#include <stdio.h>
#include <stdbool.h>
#include "hashmap.h"
#include "assembler_utils.h"

#define ERROR_ARRAY_SIZE 20
#define  LINE_LENGTH 100
#define DATA_TYPE_LABEL 1
#define EXTERNAL_TYPE_LABEL 2
#define ENTRY_TYPE_LABEL 3
#define OPCODE_TYPE_LABEL 4


typedef struct LineAndMetadata {
    int line_number;
    char *line;
    int arr_errors_codes[ERROR_ARRAY_SIZE];
//    int *arr_errors_codes;
    int is_error_occurred;
    int is_contains_label;
    char *label;
    int instruction_type;
    char *opcode_type;

};


typedef struct Operands {
    int total_operands;
    char *source_operand;
    char *destination_operand;
    int source_operand_type;
    int destination_operand_type;
} Operands;

void free_operand(Operands *operands);
//struct Arguments *initialize_arguments_struct();
bool validate_entry_and_external_label(char *, struct LabelSection *);

bool verify_operand_amount(Operands *operands, int operand_number);

bool verify_operands(Operands *operands, int operand_number, struct LineAndMetadata *lineAndMetadata);

int classified_operands(char *operands);

bool verify_operand_type(Operands *, struct LineAndMetadata *);

bool verify_operands_syntax(Operands *operands, int operand_number);

int calculate_first_line(Operands *, struct LineAndMetadata *);

void *
insert_opcode_line_to_image(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection, Operands *);

void *get_data_arguments(struct LineAndMetadata *);

void *validate_and_insert_external_arguments(struct LineAndMetadata *, struct LabelSection *);

void *validate_and_insert_string_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection);

void *validate_and_insert_data_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection);

void *validate_and_insert_struct_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection);

void *get_struct_arguments(struct LineAndMetadata *);

bool validate_data_type(struct LineAndMetadata *);

bool validate_string_type(struct LineAndMetadata *);

bool validate_struct_type(struct LineAndMetadata *);

void *
validate_and_insert_instruction_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection);

bool validate_label(struct LineAndMetadata *, struct LabelSection *);

void add_error_code(struct LineAndMetadata *, int);

int is_empty_or_comment(char *);

void insert_data_label_into_table(struct LabelSection *, struct LineAndMetadata *);

void insert_opcode_label_into_table(struct LabelSection *, struct LineAndMetadata *);

void *validate_and_insert_opcode_line(struct LineAndMetadata *, struct LabelSection *);

void insert_external_or_entry_label_into_table(char *label, struct LabelSection *labelSection, int type);

char *get_opcode(struct LineAndMetadata *);

Operands *get_operands_and_type(struct LineAndMetadata *lineAndMetadata);

void *
validate_and_insert_entry_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection);

int first_iteration(char *);


bool get_and_validate_label(struct LineAndMetadata *lineAndMetadata, struct LabelSection *);

void print_errors(struct LineAndMetadata *lineAndMetadata, int line);

struct LineAndMetadata *initialize_line_and_metadata(char *line, int line_number);

char *calculate_line_for_second_iteration(struct LabelSection *labelSection, int position);

void free_line_and_metadata(struct LineAndMetadata *lineAndMetadata);

char *get_label(char *line);

int get_data_instruction(struct LineAndMetadata *lineAndMetadata);

void *handle_data_instruction(struct LineAndMetadata *, struct LabelSection *);

void *handle_data_type_without_symbol(struct LineAndMetadata *);

void *handle_data_type_with_label(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection);

void *handle_operation(struct LineAndMetadata *, struct LabelSection *labelSection);

char *validate_instruction(char *instruction_word);

#endif //MAMN14_ASSEMBLER_ITERATIONS_H
