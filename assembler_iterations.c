#include <stdlib.h>
#include "assembler_iterations.h"
#include "hashmap.h"
#include "assembler_utils.h"
#include "file_utils.h"
#include <string.h>
#include "constants.h"
#include "errors_utils.h"
#include <stdbool.h>

int first_iteration(char *program_file_path) {
    bool is_error_occurred = false;
    FILE *assembly_file = open_read_file_else_exit(program_file_path);

    //trim the ".am" extension and add ".o" extension
    char *output_file_name = get_name_with_new_file_extension(program_file_path, ".o", 3);
    //open new file for writing.
    FILE *output_file = open_write_file_else_exit(output_file_name);

    //struct that contains the Instruction Counter, Data Counter and The Symbol table for later use.
    struct LabelSection *labelSection = initialize_label_section();

    int is_symbol = 0; //flag that indicates if the line started with symbol (for instance: "MAIN: mov r1 r2")

    char *line = malloc(sizeof(char) * LINE_LENGTH);
    int line_num = 0; //indicates the current line number

    while (fgets(line, LINE_LENGTH, assembly_file)) {
        line_num++;

        //first check if its empty line or comment line, if so continue to the next line.
        if (is_empty_or_comment(line))
            continue;

        //TODO:done
        struct LineAndMetadata *lineAndMetadata = initialize_line_and_metadata(line, line_num);
        bool if_exists_is_label_valid = get_and_validate_label(lineAndMetadata, labelSection);

        if (if_exists_is_label_valid ==
            false) { //if the label is illegal then print the error and keep to the next line
            print_errors(lineAndMetadata);
            is_error_occurred = true;
            continue;
        }


        //return the instruction_type type, null if not an instruction_type line
        char *data_instruction_type = get_data_instruction(lineAndMetadata); //TODO: done

        //return the opcode_type code , null if not an opcode_type line
        char *opcode_type = get_opcode(lineAndMetadata);


        if (data_instruction_type != NULL) {
            lineAndMetadata->instruction_type = data_instruction_type;
            handle_data_instruction(lineAndMetadata, labelSection);
        } else if (opcode_type != NULL)//in caits an operation line.
            handle_operation(lineAndMetadata, labelSection);

    }
    return is_error_occurred;//return 1 if any error occurred so the assembler won't proceed to the second iteration

}

void print_errors(struct LineAndMetadata *lineAndMetadata) {
    //iterate over the array as long as != 0 and get the error string from the error map and print to console.
    for (int i = 0; lineAndMetadata->arr_errors_codes[i] != 0; i++)
        printf("%s\n", ht_search(get_errors_map(), lineAndMetadata->arr_errors_codes[i]));
}


int is_empty_or_comment(char *line) {
    char first_char = line;
    if (first_char == '\n' || first_char == ';')
        return 1;
    else
        return 0;
}


char *get_opcode(struct LineAndMetadata *lineAndMetadata) {
    char *line_copy = malloc(sizeof(char) * LINE_LENGTH);
    strcpy(line_copy, lineAndMetadata->line);

    if (lineAndMetadata->is_contains_label) {//if the line contains label the instruction_type word may be the second
        char *word = strtok(line_copy, " ");
        word = strtok(NULL, " ");
        return ht_search(get_opcode_and_decimal_map(), word);

    } else {
        char *word = strtok(line_copy, " ");
        return ht_search(get_opcode_and_decimal_map(), word);
    }
}


struct LineAndMetadata *initialize_line_and_metadata(char *line, int line_number) {
    struct LineAndMetadata *lineAndMetadata = malloc(sizeof(struct LineAndMetadata));
    lineAndMetadata->line = line;
    lineAndMetadata->line_number = line_number;
    lineAndMetadata->is_contains_label = 0;
    lineAndMetadata->is_error_occurred = 0;
    lineAndMetadata->label = NULL;
    memset(lineAndMetadata->arr_errors_codes, 0, ERROR_ARRAY_SIZE * sizeof(int));
    return lineAndMetadata;
}

void *handle_data_instruction(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    if (lineAndMetadata->is_contains_label)
        return handle_data_type_with_label(lineAndMetadata, labelSection);
    else
        return handle_data_type_without_symbol(lineAndMetadata);
}


void *handle_data_type_with_label(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
//    int is_label_valid = validate_label(lineAndMetadata, labelSection->label_table);
    validate_instruction_arguments(lineAndMetadata);
    insert_data_label_into_table(lineAndMetadata, labelSection);


}

bool validate_instruction_arguments(struct LineAndMetadata *lineAndMetadata) {
    switch (lineAndMetadata->instruction_type) {
        case 1:
            return validate_data_type(lineAndMetadata);
            break;
        case 2:
            return validate_string_type(lineAndMetadata);
            break;
        case 3:
            return validate_struct_type(lineAndMetadata);
            break;
    }

}

bool validate_data_type(struct LineAndMetadata *lineAndMetadata) {


}

bool validate_string_type(struct LineAndMetadata *lineAndMetadata) {
    void *arguments = get_arguments(lineAndMetadata);


}


bool validate_struct_type(struct LineAndMetadata *lineAndMetadata) {


}


//struct Arguments *initialize_arguments_struct() {
//    struct Arguments *arguments = malloc(sizeof(struct Arguments));
//    arguments->integer_arguments_counter = 0;
//    arguments->string_arguments_counter = 0;
//    return arguments;
//}


void *get_string_arguments(struct LineAndMetadata *);

void *get_struct_arguments(struct LineAndMetadata *);


void *get_data_arguments(struct LineAndMetadata *lineAndMetadata) {
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char));
    strcpy(line_copy, lineAndMetadata->line);

    struct DataArguments *dataArguments = malloc(sizeof(struct DataArguments));

    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");

    } else
        word = strtok(line_copy, " ");

    while (word = strtok(NULL, ",") != NULL) {


    }

}


/**validate the label of the line,
 *  check if already in use or if name of opcode_type or instruction_type.
 * @return false in case of invalid label.
 * @return true in case of valid label.
 * */
bool validate_label(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    char *label = lineAndMetadata->label;
    if (ht_search(labelSection->label_table, label) != NULL) { //if the label already in use then add error and return.
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata->arr_errors_codes, ERR_CODE_LABEL_ALREADY_IN_USE);
        return false;
    } else if (ht_search(get_data_instruction_map(), label) != NULL) {//if the label is instruction_type label.
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata->arr_errors_codes, ERR_CODE_LABEL_IS_INSTRUCTION);
        return false;
    } else if (ht_search(get_opcode_and_decimal_map(), label) != NULL) {//if the label is opcode_type operation.
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata->arr_errors_codes, ERR_CODE_LABEL_IS_OPERATION);
        return false;
    } else if (ht_search(get_registers_map(), label) != NULL) {//if the label is a register name.
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata->arr_errors_codes, ERR_CODE_LABEL_IS_REGISTER);
        return false;
    } else
        return true;

}

void insert_data_label_into_table(struct LabelSection *labelSection, struct LineAndMetadata *lineAndMetadata) {
    int *counter_and_type = calloc(2, sizeof(int));
    counter_and_type[0] = 1; //indicates its a data type label
    counter_and_type[1] = labelSection->dc;
    ht_insert(labelSection->label_table, lineAndMetadata->label, counter_and_type);
}


void *handle_data_type_without_symbol(struct LineAndMetadata *line) {}


//checks if the line starts with symbol, if so return the label, else return null.
char *get_label(char *line) {
    char *line_copy = malloc(sizeof(char) * strlen(line));
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

    char *line_copy = malloc(sizeof(char) * strlen(lineAndMetadata->line));
    strcpy(line_copy, lineAndMetadata->line);


    if (lineAndMetadata->is_contains_label) {//if the line contains label the instruction_type word may be the second
        char *word = strtok(line_copy, " ");
        word = strtok(NULL, " ");
        if (ht_search(get_data_instruction_map(),
                      word) != NULL)
            return word; //find the instruction_type in the instruction_type table. if not exist return NULL
    } else {
        char *word = strtok(line_copy, " ");
        if (ht_search(get_data_instruction_map(),
                      word) != NULL)
            return true; //find the instruction_type in the instruction_type table. if not exist return NULL
    }

}

char *validate_instruction(char *word) { //TODO: implementation done
    char starting_char = *word; //fetch the first character
    char *valid_word = ht_search(get_data_instruction_map(),
                                 word); //find the instruction_type in the instruction_type table
    if (starting_char != '.') //if the word doesn't start with "."
        return NULL;
    else
        return valid_word; //NULL if its invalid instruction_type.

}

bool get_and_validate_label(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    char *label = get_label(lineAndMetadata->line); //return the label, null if line is not starting with label
    if (label != NULL) {
        lineAndMetadata->is_contains_label = 1;
        lineAndMetadata->label = label;
        bool is_valid_label = validate_label(lineAndMetadata, labelSection);
        if (is_valid_label == false) {
            return false;
        } else return true;
    } else return NULL;
}


void add_error_code(struct LineAndMetadata *lineAndMetadata, int error_code) {
    for (int i = 0; i < ERROR_ARRAY_SIZE; i++) {
        if (lineAndMetadata->arr_errors_codes[i] == 0) {
            lineAndMetadata->arr_errors_codes[i] = error_code;
            break;
        }
    }
}


void *handle_operation(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {};

