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
#include <ctype.h>

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
        } else if (opcode_type != NULL) {//in case its an operation line.
            lineAndMetadata->opcode_type = opcode_type;
            handle_operation(lineAndMetadata, labelSection);
        }

        if (lineAndMetadata->is_error_occurred)
            is_error_occurred = true;
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

void free_line_and_metadata(struct LineAndMetadata *lineAndMetadata) {
    free(lineAndMetadata->line);
    free(lineAndMetadata->label);
    free(lineAndMetadata);
}

void *handle_data_instruction(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    if (lineAndMetadata->is_contains_label) { //first if the line contain label then insert it.
        insert_data_label_into_table(lineAndMetadata, labelSection);
    }
    validate_and_insert_instruction_arguments(lineAndMetadata, labelSection);
}


void *
validate_and_insert_instruction_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    switch (lineAndMetadata->instruction_type) {
        case DATA_TYPE:
            return validate_and_insert_data_arguments(lineAndMetadata, labelSection);
        case STRING_TYPE:
            return validate_and_insert_string_arguments(lineAndMetadata, labelSection);
        case STRUCT_TYPE:
            return validate_and_insert_struct_arguments(lineAndMetadata, labelSection);
        case ENTRY_TYPE:
            return validate_and_insert_entry_arguments(lineAndMetadata, labelSection);
        case EXTERNAL_TYPE:
            return validate_and_insert_external_arguments(lineAndMetadata, labelSection);
    }

}

void *
validate_and_insert_entry_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char));
    strcpy(line_copy, lineAndMetadata->line);

    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");

    } else
        word = strtok(line_copy, " ");

    word = strtok(NULL, " ");
    bool is_valid_label = validate_entry_and_external_label(word, labelSection);
    if (is_valid_label) {
        insert_external_or_entry_label_into_table(word, labelSection, ENTRY_TYPE_LABEL);
        return true;
    } else {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_ARGUMENTS);
        return false;
    }

}


void *
validate_and_insert_external_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char));
    strcpy(line_copy, lineAndMetadata->line);

    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");

    } else
        word = strtok(line_copy, " ");

    word = strtok(NULL, " ");
    bool is_valid_label = validate_entry_and_external_label(word, labelSection);
    if (is_valid_label) {
        insert_external_or_entry_label_into_table(word, labelSection, EXTERNAL_TYPE_LABEL);
        return true;
    } else {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_ARGUMENTS);
        return false;
    }
}


void *validate_and_insert_string_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char));
    strcpy(line_copy, lineAndMetadata->line);

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
    int temp_dc = labelSection->dc;
    for (int i = 0; i < strlen(word); i++) {
        labelSection->data_array[temp_dc] = (int) word[i];
        temp_dc++;
    }

    word = strtok(NULL, " ");

    if (word != NULL) {
        lineAndMetadata->is_error_occurred = 1; //too many arguments
        add_error_code(lineAndMetadata, ERR_CODE_TOO_MANY_ARGUMENTS);
        return NULL;
    }
    labelSection->dc = temp_dc; //in case the job done properly then update the dc
    free(line_copy);
    return true;

}

void *validate_and_insert_struct_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char));
    strcpy(line_copy, lineAndMetadata->line);


    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");

    } else
        word = strtok(line_copy, " ");

    int temp_dc = labelSection->dc;
    int number = string_to_number(word);
    if (number == NULL) {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_DATA_TYPE);
        return NULL;
    }

    labelSection->data_array[temp_dc] = number;
    temp_dc++;

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
        labelSection->data_array[temp_dc] = (int) word[i];
        temp_dc++;
    }

    word = strtok(NULL, " ");

    if (word != NULL) {
        lineAndMetadata->is_error_occurred = 1; //too many arguments
        add_error_code(lineAndMetadata, ERR_CODE_TOO_MANY_ARGUMENTS);
        return NULL;
    }
    labelSection->dc = temp_dc;//in case the job done properly then update the dc;
    free(line_copy);
    return true;


}


void *validate_and_insert_data_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char));
    strcpy(line_copy, lineAndMetadata->line);

    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");

    } else
        word = strtok(line_copy, " ");

    int temp_dc = labelSection->dc;
    while (word = strtok(NULL, ",") != NULL) {
        long number = string_to_number(word);
        if (number == NULL) { //in case the input is not a valid number
            lineAndMetadata->is_error_occurred = 1;
            add_error_code(lineAndMetadata, ERR_CODE_INVALID_DATA_TYPE);
            return NULL;
        } else {
            labelSection->data_array[temp_dc] = number;
        }
        temp_dc++;
    }
    labelSection->dc = temp_dc; //in case the data was validated and the insert done properly then update the dc;
    free(line_copy);
    return true;

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

bool validate_entry_and_external_label(char *label, struct LabelSection *labelSection) {
    if (ht_search(labelSection->label_table, label) != NULL)  //if the label already in use then add error and return.
        return false;
    else if (ht_search(get_data_instruction_map(), label) != NULL) //if the label is instruction_type label.
        return false;
    else if (ht_search(get_opcode_and_decimal_map(), label) != NULL) //if the label is opcode_type operation.
        return false;
    else if (ht_search(get_registers_map(), label) != NULL) //if the label is a register name.
        return false;
    else
        return true;
}

void insert_external_or_entry_label_into_table(char *label, struct LabelSection *labelSection, int type) {
    int *counter_and_type = calloc(2, sizeof(int));
    counter_and_type[0] = type; //indicates its a data type label
    counter_and_type[1] = 0;
    ht_insert(labelSection->label_table, label, counter_and_type);
}

void insert_data_label_into_table(struct LabelSection *labelSection, struct LineAndMetadata *lineAndMetadata) {
    int *counter_and_type = calloc(2, sizeof(int));
    counter_and_type[0] = DATA_TYPE_LABEL; //indicates its a data type label
    counter_and_type[1] = labelSection->dc;
    ht_insert(labelSection->label_table, lineAndMetadata->label, counter_and_type);
}


void insert_opcode_label_into_table(struct LabelSection *labelSection, struct LineAndMetadata *lineAndMetadata) {
    int *counter_and_type = calloc(2, sizeof(int));
    counter_and_type[0] = OPCODE_TYPE_LABEL; //indicates its a opcode type label
    counter_and_type[1] = labelSection->ic;
    ht_insert(labelSection->label_table, lineAndMetadata->label, counter_and_type);
}

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

void *validate_and_insert_opcode_line(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    int operand_number = ht_search(get_opcode_and_amount_of_operands_map(), lineAndMetadata->opcode_type);
    Operands *operands = get_operands_and_type(lineAndMetadata);
    bool is_operand_valid = verify_operands(operands, operand_number, NULL);

    if (!is_operand_valid) {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_OPERANDS);
        return NULL;
    }
    insert_opcode_line_to_image(lineAndMetadata, labelSection, operands);


}

void *insert_opcode_line_to_image(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection,
                                  Operands *operands) {
    int temp_ic = labelSection->ic; //use temporary index and update the ic only if the operation done properly.
    int first_line = calculate_first_line(operands, lineAndMetadata);

    labelSection->instruction_array[temp_ic] = first_line;
    temp_ic++;

}


int calculate_first_line(Operands *operands, struct LineAndMetadata *lineAndMetadata) {
    int line_sum = 0;
    int operand_code = ht_search(get_opcode_and_decimal_map(), lineAndMetadata->opcode_type);
    operand_code = operand_code << 6; //move the operation code to be the 4  greater bits.
    line_sum += operand_code; //add the operand code to the line sum.

    int source_code = operands->source_operand_type;
    if (source_code != NULL) {
        source_code = source_code << 4;
        line_sum += source_code;
    }

    int dest_code = operands->destination_operand_type;
    if (dest_code != NULL) {
        dest_code = dest_code << 2;
        line_sum += dest_code;
    }


}


Operands *get_operands_and_type(struct LineAndMetadata *lineAndMetadata) {
    Operands *operands = malloc(sizeof(Operands));
    char *line_copy = malloc(sizeof(char) * strlen(lineAndMetadata->line));

    if (lineAndMetadata->is_contains_label) { //first normalize the pointer. if the line contains label the opcode word may be the second
        char *word = strtok(line_copy, " ");
        word = strtok(NULL, " ");
    } else
        char *word = strtok(line_copy, " ");

    operands->source_operand = strtok(NULL, " "); //NULL if no operand
    operands->destination_operand = strtok(NULL, " ");//NULL if no operands/only 1 operand.

    operands->source_operand_type = classified_operands(operands->source_operand);
    operands->destination_operand_type = classified_operands(operands->destination_operand);

    return operands;

}

bool verify_operands(Operands *operands, int operand_number, struct LineAndMetadata *lineAndMetadata) {
    bool amount = verify_operand_amount(operands, operand_number);
    bool syntax = verify_operands_syntax(operands, operand_number);
    bool type = verify_operand_type(operands, lineAndMetadata);

    return amount && syntax && type;

}

bool verify_operand_type(Operands *operands, struct LineAndMetadata *lineAndMetadata) {
    int *valid_addressing_source = ht_search(get_valid_source_addressing_map(), lineAndMetadata->opcode_type);
    int *valid_addressing_dest = ht_search(get_valid_dest_addressing_map(), lineAndMetadata->opcode_type);

//    if (valid_addressing_source != NULL && operands->source_operand_type != NULL)


}

bool verify_operand_amount(Operands *operands, int operand_number) {
    int current_operands = 0;

    if (operands->destination_operand != NULL)
        current_operands++;
    if (operands->source_operand != NULL)
        current_operands++;

    if (current_operands != operand_number)
        return false;
}


bool verify_operands_syntax(Operands *operands, int operand_number) {

    if (operands->source_operand != NULL && operands->source_operand_type == NULL)
        return false;
    else if (operands->destination_operand != NULL && operands->destination_operand_type == NULL)
        return false;
    else return true;
}


int classified_operands(char *operand) {
    if (operand == NULL)
        return NULL;

    char first_char = *operand;
    if (first_char == '#')
        return IMMEDIATE_ADDRESSING_OPERAND;
    else if (ht_search(get_registers_map(), operand) != NULL)
        return REGISTER_ADDRESSING_OPERAND;
    else if (isalpha(first_char)) {
        if (operand[strlen(operand) - 2] == '.' &&
            (operand[strlen(operand) - 1] == '1' ||
             operand[strlen(operand) - 1] == '2')) //in case this is strcut type operand (AB.1 for instance)
            return DIRECT_OFFSET_ADDRESSING_OPERAND;
        else
            return DIRECT_ADDRESSING_OPERAND;
    } else
        return NULL;

}

void *handle_operation(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    if (lineAndMetadata->is_contains_label) {
        insert_opcode_label_into_table(labelSection, lineAndMetadata);
    }
    validate_and_insert_opcode_line(lineAndMetadata, labelSection);

}

