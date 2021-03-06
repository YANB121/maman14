#include <process.h>
#include <stdlib.h>
#include "assembler_iterations.h"
#include "utils/hashmap.h"
#include "utils/assembler_utils.h"
#include "utils/file_utils.h"
#include <string.h>


#define  LINE_LENGTH 100


void first_iteration(char *program_file_path) {
    FILE *assembly_file = open_read_file_else_exit(program_file_path);

    struct SymbolsSection *symbolsSection = initialize_symbol_section();

    int is_symbol = 0; //flag that indicates if the line started with symbol (for instance: "MAIN: mov r1 r2")

    char *line = malloc(sizeof(char) * LINE_LENGTH);
    int line_num = 0; //indicates the current line number

    int is_error_occurred = 0;


    while (fgets(line, LINE_LENGTH, assembly_file)) {
        line_num++;
        struct LineAndMetadata *lineAndMetadata = initialize_line_and_metadata(line, line_num);

        char *symbol = get_symbol(line); //return the symbol, null if line is not starting with symbol

        if (symbol != NULL)
            lineAndMetadata->is_contains_label = 1;

        //return the instruction type, null if not an instruction line
        char *instruction_type = get_instruction(lineAndMetadata);
        if (instruction_type != NULL)
            handle_data_instruction(line, is_symbol, symbolsSection);
        else //in case its an operation line.
            handle_operation(line, is_symbol, symbolsSection);

    }

}


struct LineAndMetadata *initialize_line_and_metadata(char *line, int line_number) {
    struct LineAndMetadata *lineAndMetadata = malloc(sizeof(struct LineAndMetadata));
    lineAndMetadata->line = line;
    lineAndMetadata->line_number = line_number;
    lineAndMetadata->is_contains_label = 0;
    lineAndMetadata->is_error_occurred = 0;
    return lineAndMetadata;
}

void *handle_data_instruction(char *line, int contains_symbol, struct SymbolsSection *symbolsSection) {
    if (contains_symbol)
        return handle_data_type_with_symbol(line);
    else
        return handle_data_type_without_symbol(line);
}


void *handle_data_type_with_symbol(char *line) {}

void *handle_data_type_without_symbol(char *line) {}

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
char *get_instruction(struct LineAndMetadata *lineAndMetadata) {

    char *line_copy = malloc(sizeof(lineAndMetadata->line));
    strcpy(line_copy, lineAndMetadata->line);


    if (lineAndMetadata->is_contains_label) {//if the line contains label the instruction word may be the second
        char *word = strtok(line_copy, " ");
        word = strtok(NULL, " ");
        return validate_instruction(word);

    } else {
        char *word = strtok(line_copy, " ");
        return validate_instruction(word);


    }


}

char *validate_instruction(char *word) {
    char starting_char = *word;
    if (starting_char != ".")
        return NULL;
    else if (){


    }

}


void second_iteration(char *) {};

void *handle_operation(char *line, int contains_symbol, struct SymbolsSection *symbolsSection) {};

