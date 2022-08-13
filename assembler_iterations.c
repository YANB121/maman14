#include <stdlib.h>
#include "assembler_iterations.h"
#include "hashmap.h"
#include "assembler_utils.h"
#include "file_utils.h"
#include <string.h>
#include "constants.h"
#include "errors_utils.h"
#include "input_utils.h"
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
        int data_instruction_type = get_data_instruction(lineAndMetadata); //TODO: done

        //return the opcode_type code , null if not an opcode_type line
        char *opcode_type = get_opcode(lineAndMetadata);


        if (data_instruction_type != NULL) {
            lineAndMetadata->instruction_type = data_instruction_type;
            handle_data_instruction(lineAndMetadata, labelSection);
        } else if (opcode_type != NULL)//in case its an operation line.
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
    char first_char = *line;
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
    void *arguments = validate_and_get_instruction_arguments(lineAndMetadata);
    insert_data_label_into_table(lineAndMetadata, labelSection);


}

void *validate_and_get_instruction_arguments(struct LineAndMetadata *lineAndMetadata) {
    switch (lineAndMetadata->instruction_type) {
        case 1:
            return validate_and_get_data_arguments(lineAndMetadata);
        case 2:
            return validate_get_string_arguments(lineAndMetadata);
        case 3:
            return validate_and_get_struct_arguments(lineAndMetadata);

    }

}


void *validate_get_string_arguments(struct LineAndMetadata *lineAndMetadata) {
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char));
    strcpy(line_copy, lineAndMetadata->line);

    struct DataArguments *dataArguments = malloc(sizeof(struct DataArguments));
    dataArguments->data_arguments_counter = 0;

    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");

    } else
        word = strtok(line_copy, " ");

    char first_char = *word;
    char last_char = word[strlen(word) - 1];
    if (first_char != '"' || last_char != '"') {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_STRING_TYPE);
        return NULL;
    }
    word = trim_commas(word);

    for (int i = 0; i < strlen(word); i++) {
        dataArguments->data_arguments[dataArguments->data_arguments_counter] = (int) word[i];
        dataArguments->data_arguments_counter = dataArguments->data_arguments_counter + 1;
    }

    word = strtok(NULL, " ");

    if (word != NULL) {
        lineAndMetadata->is_error_occurred = 1; //too many arguments
        add_error_code(lineAndMetadata, ERR_CODE_TOO_MANY_ARGUMENTS);
        return NULL;
    }

    free(line_copy);
    return dataArguments;

}

void *validate_and_get_struct_arguments(struct LineAndMetadata *lineAndMetadata) {
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char));
    strcpy(line_copy, lineAndMetadata->line);

    struct DataArguments *dataArguments = malloc(sizeof(struct DataArguments));
    dataArguments->data_arguments_counter = 0;

    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");

    } else
        word = strtok(line_copy, " ");

    int number = string_to_number(word);
    if (number == NULL) {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_DATA_TYPE);
        return NULL;
    }
    dataArguments->data_arguments[dataArguments->data_arguments_counter] = number;
    dataArguments->data_arguments_counter++;

    word = strtok(NULL, ",");
    char first_char = *word;
    char last_char = word[strlen(word) - 1];
    if (first_char != '"' || last_char != '"') {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_STRING_TYPE);
        return NULL;
    }
    word = trim_commas(word);

    for (int i = 0; i < strlen(word); i++) {
        dataArguments->data_arguments[dataArguments->data_arguments_counter] = (int) word[i];
        dataArguments->
                data_arguments_counter = dataArguments->data_arguments_counter + 1;
    }

    word = strtok(NULL, " ");

    if (word != NULL) {
        lineAndMetadata->is_error_occurred = 1; //too many arguments
        add_error_code(lineAndMetadata, ERR_CODE_TOO_MANY_ARGUMENTS);
        return NULL;
    }
    free(line_copy);
    return dataArguments;


}


void *validate_and_get_data_arguments(struct LineAndMetadata *lineAndMetadata) {
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char));
    strcpy(line_copy, lineAndMetadata->line);

    struct DataArguments *dataArguments = malloc(sizeof(struct DataArguments));
    dataArguments->data_arguments_counter = 0;

    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");

    } else
        word = strtok(line_copy, " ");

    while (word = strtok(NULL, ",") != NULL) {
        long number = string_to_number(word);
        if (number == NULL) { //in case the input is not a valid number
            lineAndMetadata->is_error_occurred = 1;
            add_error_code(lineAndMetadata, ERR_CODE_INVALID_DATA_TYPE);
            return NULL;
        } else {
            dataArguments->data_arguments[dataArguments->data_arguments_counter] = number;
        }
        dataArguments->data_arguments_counter = dataArguments->data_arguments_counter + 1;
    }
    free(line_copy);
    return dataArguments;

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
    counter_and_type[0] = DATA_TYPE_LABEL; //indicates its a data type label
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
int get_data_instruction(struct LineAndMetadata *lineAndMetadata) {

    char *line_copy = malloc(sizeof(char) * strlen(lineAndMetadata->line));
    strcpy(line_copy, lineAndMetadata->line);


    if (lineAndMetadata->is_contains_label) {//if the line contains label the instruction_type word may be the second
        char *word = strtok(line_copy, " ");
        word = strtok(NULL, " ");
        int data_type = ht_search(get_data_instruction_map(), word);
        if (data_type != NULL)
            return data_type; //find the instruction_type in the instruction_type table. if not exist return NULL
        else return NULL;
    } else {
        char *word = strtok(line_copy, " ");
        int data_type = ht_search(get_data_instruction_map(), word);
        if (data_type != NULL)
            return data_type; //find the instruction_type in the instruction_type table. if not exist return NULL
        else return NULL;
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

