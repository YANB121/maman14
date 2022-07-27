#include <stdlib.h>
#include "assembler_iterations.h"
#include "utils/hashmap.h"
#include "utils/assembler_utils.h"
#include "utils/file_utils.h"
#include <string.h>
//#include <libgen.h>
#include "utils/constants.h"
#include "utils/errors_utils.h"




int first_iteration(char *program_file_path) {
    int is_error_occurred = 0;
    FILE *assembly_file = open_read_file_else_exit(program_file_path);

    //trim the ".am" extension and add ".o" extension
    char *output_file_name = get_name_with_new_file_extension(program_file_path, ".o", 3);
    //open new file for writing.
    FILE *output_file = open_write_file_else_exit(output_file_name);

    //struct that contains the Instruction Counter, Data Counter and The Symbol table for later use.
    struct LabelSection *symbolsSection = initialize_label_section();

    int is_symbol = 0; //flag that indicates if the line started with symbol (for instance: "MAIN: mov r1 r2")

    char *line = malloc(sizeof(char) * LINE_LENGTH);
    int line_num = 0; //indicates the current line number

    while (fgets(line, LINE_LENGTH, assembly_file)) {
        line_num++;

        //first check if its empty line or comment line, if so continue to the next line.
        if (is_empty_or_comment(line))
            continue;


        //TODO:done
        char *label = get_symbol(line); //return the label, null if line is not starting with label
        struct LineAndMetadata *lineAndMetadata = initialize_line_and_metadata(line, line_num);

        if (label != NULL) {
            lineAndMetadata->is_contains_label = 1;
            lineAndMetadata->label = label;
        }
        //return the instruction type, null if not an instruction line
        char *data_instruction_type = get_data_instruction(lineAndMetadata); //TODO: done

        //return the opcode code , null if not a opcode line
        char *opcode_type = get_opcode(lineAndMetadata);

        if (data_instruction_type != NULL)
            handle_data_instruction(lineAndMetadata, symbolsSection);
        else if (opcode_type != NULL)//in case its an operation line.
            handle_operation(lineAndMetadata, symbolsSection);

    }
    return is_error_occurred;//return 1 if any error occurred so the assembler won't proceed to the second iteration

}


int is_empty_or_comment(char *line) {
    char first_char = line;
    if (first_char == '\n' || first_char == ';')
        return 1;
    else
        return 0;
}


char *get_opcode(struct LineAndMetadata *lineAndMetadata) {
    char *line_copy = malloc(sizeof(char)*LINE_LENGTH);
    strcpy(line_copy, lineAndMetadata->line);

    if (lineAndMetadata->is_contains_label) {//if the line contains label the instruction word may be the second
        char *word = strtok(line_copy, " ");
        word = strtok(NULL, " ");
        return ht_search(opcodeAndDecimal, word);

    } else {
        char *word = strtok(line_copy, " ");
        return ht_search(opcodeAndDecimal, word);
    }
}


struct LineAndMetadata *initialize_line_and_metadata(char *line, int line_number) {
    struct LineAndMetadata *lineAndMetadata = malloc(sizeof(struct LineAndMetadata));
    lineAndMetadata->line = line;
    lineAndMetadata->line_number = line_number;
    lineAndMetadata->is_contains_label = 0;
    lineAndMetadata->is_error_occurred = 0;
    memset(lineAndMetadata->errors_codes, 0, ERROR_ARRAY_SIZE);
    return lineAndMetadata;
}

void *handle_data_instruction(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    if (lineAndMetadata->is_contains_label)
        return handle_data_type_with_label(lineAndMetadata, labelSection);
    else
        return handle_data_type_without_symbol(lineAndMetadata);
}


void *handle_data_type_with_label(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    int is_label_valid = validate_label(lineAndMetadata, labelSection->label_table);
    insert_data_label_into_table(lineAndMetadata, labelSection);


}

void *validate_label(struct LineAndMetadata *lineAndMetadata, HashTable *label_table) {
    char *label = lineAndMetadata->label;
    if (ht_search(label_table, label)) { //if the label already in use then add error and return.
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata->errors_codes, ERR_CODE_LABEL_ALREADY_IN_USE);

    }


}


void insert_data_label_into_table(struct LabelSection *labelSection, struct LineAndMetadata *lineAndMetadata) {
    int *counter_and_type = calloc(2, sizeof(int));
    counter_and_type[0] = 1; //indicates its a data type label
    counter_and_type[1] = labelSection->dc;
    ht_insert(labelSection->label_table, lineAndMetadata->label, counter_and_type);
}


void *handle_data_type_without_symbol(struct LineAndMetadata *line) {}

//checks if the line starts with symbol, if so return the label, else return null.
char *get_symbol(char *line) {
    char *line_copy = malloc(sizeof(line));
    strcpy(line_copy, line);

    char *first_word = strtok(line_copy, " ");
    char *last_char = &first_word[strlen(first_word) - 1];

    //  free(line_copy);

    if (!strcmp(last_char, ":")) {//strcmp returns 0 if the 2 strings equals
        first_word[strlen(first_word) - 1] = '\0'; //remove the ":" from the word.
        return first_word;
    } else
        return NULL;


    line_copy = strtok(line_copy, ":");

}

//checks if its data line , if so return the data type (".struct",".data",".string", etc'), else return null.
char *get_data_instruction(struct LineAndMetadata *lineAndMetadata) {

    char *line_copy = malloc(sizeof(lineAndMetadata->line));
    strcpy(line_copy, lineAndMetadata->line);


    if (lineAndMetadata->is_contains_label) {//if the line contains label the instruction word may be the second
        char *word = strtok(line_copy, " ");
        word = strtok(NULL, " ");
        return ht_search(dataInstructions,
                         word); //find the instruction in the instruction table. if not exist return NULL
    } else {
        char *word = strtok(line_copy, " ");
        return ht_search(dataInstructions,
                         word); //find the instruction in the instruction table. if not exist return NULL



    }


}

char *validate_instruction(char *word) { //TODO: implementation done
    char starting_char = *word; //fetch the first character
    char *valid_word = ht_search(dataInstructions, word); //find the instruction in the instruction table
    if (starting_char != '.') //if the word doesn't start with "."
        return NULL;
    else
        return valid_word; //NULL if its invalid instruction.

}


void second_iteration(char *file_path) {};

void *handle_operation(struct LineAndMetadata *lineAndMetadata, struct LabelSection *symbolsSection) {};

