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

int first_iteration(char *program_file_path, struct LabelSection *labelSection) {
    bool is_error_occurred = false;
    FILE *assembly_file = open_read_file_else_exit(program_file_path);

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
            print_errors(lineAndMetadata, line_num);
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
        } else if (opcode_type != NULL) {//in case it's an operation line.
            lineAndMetadata->opcode_type = opcode_type;
            handle_operation(lineAndMetadata, labelSection);
        }

        if (lineAndMetadata->is_error_occurred) {
            print_errors(lineAndMetadata, line_num);
            is_error_occurred = true;
        }

        free(lineAndMetadata);

    }
    update_label_table(labelSection);

    return is_error_occurred;//return 1 if any error occurred so the assembler won't proceed to the second iteration

}


int second_iteration(char *program_file_path, struct LabelSection *labelSection) {


    bool is_error_occurred = false;

    for (int i = 0; i < MAX_PROGRAM_LENGTH; i++) {
        if (labelSection->instruction_array[i] == NULL)
            break; //exit the loop when program ended

        char first_char = *labelSection->instruction_array[i];


        if (first_char == '1' || first_char == '0')
            continue; //in case we already  parse the line in the previous iteration
        else { //if the line not yet parsed its means that its a label line.
            int *label_arr = ht_search(labelSection->label_table, labelSection->instruction_array[i]);
            if (label_arr == NULL) {
                is_error_occurred = true;
                printf("the label: %s , doesn't exist", labelSection->instruction_array[i]);
                exit(1);
            } else {
                if (label_arr[0] == EXTERNAL_TYPE_LABEL)
                    for (int j = 2; j < 10; j++)
                        if (label_arr[j] == 0) {
                            label_arr[j] = i;
                            break;
                        }
                char *line = calculate_line_for_second_iteration(labelSection, i);
                labelSection->instruction_array[i] = line;
            }

        }


    }

    for (int i = 0; i < 1000; i++) {
        if (labelSection->instruction_array[i] != NULL)
            printf("%s\n", labelSection->instruction_array[i]);

    }

}

void update_label_table(struct LabelSection *labelSection) {
    char **keys = get_keys(labelSection->label_table);
    int ic = labelSection->ic;
    for (int i = 0; i < MAX_LABELS; i++) {
        if (keys[i] == NULL)
            break;
        int *label_arr = ht_search(labelSection->label_table, keys[i]);
        int type_code = label_arr[0];
        if (type_code == DATA_TYPE_LABEL)
            label_arr[1] = label_arr[1] + ic;

    }
}


char *calculate_line_for_second_iteration(struct LabelSection *labelSection, int position) {
    char *label = labelSection->instruction_array[position];
    int *label_arr = ht_search(labelSection->label_table, label);
    int type_code = label_arr[0];
    int line;
    char *converted_line;
    switch (type_code) {
        case DATA_TYPE_LABEL:
            int dc = label_arr[1];
            line = 1; //just for normalization
            line = line << 8; //move 8 bit left for adding the dc number
            line += dc;
            line = line << 2; //move nother 2 bit for the encodiong code R,E,A
            line += 2; //add encoding code 10
            converted_line = convert_number_to_binary_string(line);
            converted_line = converted_line + 1;
            return converted_line;

        case OPCODE_TYPE_LABEL:
            int ic = label_arr[1];
            line = 1; //just for normalization
            line = line << 8; //move 8 bit left for adding the dc number
            line += ic;
            line = line << 2; //move nother 2 bit for the encodiong code R,E,A
            line += 2; //add encoding code 10
            converted_line = convert_number_to_binary_string(line);
            converted_line = converted_line + 1;
            return converted_line;
        case EXTERNAL_TYPE_LABEL:
            line = 1; //just for normalization
            line = line << 10; //move 10 bit left for adding the dc number
            line += 1; //add encoding code 01
            converted_line = convert_number_to_binary_string(line);
            converted_line = converted_line + 1;
            return converted_line;


    }


}


void print_errors(struct LineAndMetadata *lineAndMetadata, int line) {
    //iterate over the array as long as != 0 and get the error string from the error map and print to console.
    for (int i = 0; lineAndMetadata->arr_errors_codes[i] != 0; i++)
        printf("error int line:%d , %s\n", line, ht_search(get_errors_map(), lineAndMetadata->arr_errors_codes[i]));
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
        word = trim_white_spaces(word);
        if (ht_search(get_opcode_and_decimal_map(), word))
            return word;

    } else {
        char *word = strtok(line_copy, " ");
        word = trim_white_spaces(word);
        if (ht_search(get_opcode_and_decimal_map(), word))
            return word;
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
    if (lineAndMetadata->is_contains_label) { //first if the line contain label then insert it.
        insert_data_label_into_table(labelSection, lineAndMetadata);
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
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char) + 1);
    strcpy(line_copy, lineAndMetadata->line);

    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");

    } else
        word = strtok(line_copy, " ");

    word = strtok(NULL, " ");
    word = trim_white_spaces(word);

    bool is_valid_label = validate_entry_and_external_label(word, labelSection);
    if (is_valid_label) {
        //insert_external_or_entry_label_into_table(word, labelSection, ENTRY_TYPE_LABEL);
        ht_insert(labelSection->entry_labels, word, 1);
        free(line_copy);
        return true;
    } else {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_ARGUMENTS);
        free(line_copy);
        return false;
    }

}


void *
validate_and_insert_external_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char) + 1);
    strcpy(line_copy, lineAndMetadata->line);

    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");

    } else
        word = strtok(line_copy, " ");

    word = strtok(NULL, " ");
    word = trim_white_spaces(word);
    bool is_valid_label = validate_entry_and_external_label(word, labelSection);
    if (is_valid_label) {
        insert_external_or_entry_label_into_table(word, labelSection, EXTERNAL_TYPE_LABEL);
        free(line_copy);
        return true;
    } else {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_ARGUMENTS);
        free(line_copy);
        return false;
    }
}


void *validate_and_insert_string_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char) + 1);
    strcpy(line_copy, lineAndMetadata->line);

    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");
        word = strtok(NULL, " ");

    } else {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");
    }

    word = trim_white_spaces(word);
    char first_char = *word;
    char last_char = word[strlen(word) - 1];
    if (first_char != '"' || last_char != '"') {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_STRING_TYPE);
        free(line_copy);
        return NULL;
    }
    word = trim_commas(word);
    int temp_dc = labelSection->dc;
    for (int i = 0; i < strlen(word); i++) {
        labelSection->data_array[temp_dc] = convert_number_to_binary_string((int) word[i]);
        temp_dc++;
    }
    labelSection->data_array[temp_dc] = convert_number_to_binary_string(0);
    temp_dc++;

    word = strtok(NULL, " ");
    word = trim_white_spaces(word);

    if (word != NULL && strcmp(word,
                               "")) { //in case the word is not null and the word is not empty string (strcmp return 0 if the string is equal)
        lineAndMetadata->is_error_occurred = 1; //too many arguments
        add_error_code(lineAndMetadata, ERR_CODE_TOO_MANY_ARGUMENTS);
        free(line_copy);
        return NULL;
    }
    labelSection->dc = temp_dc; //in case the job done properly then update the dc
    free(line_copy);
    return true;

    free(line_copy);
}

void *validate_and_insert_struct_arguments(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char) + 1);
    strcpy(line_copy, lineAndMetadata->line);


    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");

    } else
        word = strtok(line_copy, " ");

    word = strtok(NULL, " ");
    word = trim_white_spaces(word);
    int temp_dc = labelSection->dc;
    int number = string_to_number(word);
    if (number == NULL) {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_DATA_TYPE);
        return NULL;
    }

    labelSection->data_array[temp_dc] = convert_number_to_binary_string(number);
    temp_dc++;

    word = strtok(NULL, ",");
    word = trim_white_spaces(word);
    char first_char = *word;
    char last_char = word[strlen(word) - 1];
    if (first_char != '"' || last_char != '"') {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_STRING_TYPE);
        return NULL;
    }
    word = trim_commas(word);

    for (int i = 0; i < strlen(word); i++) {
        labelSection->data_array[temp_dc] = convert_number_to_binary_string((int) word[i]);
        temp_dc++;
    }
    labelSection->data_array[temp_dc] = convert_number_to_binary_string(0);
    temp_dc++;

    word = strtok(NULL, " ");
    word = trim_white_spaces(word);
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
    char *line_copy = malloc(strlen(lineAndMetadata->line) * sizeof(char) + 1);
    strcpy(line_copy, lineAndMetadata->line);

    char *word;
    if (lineAndMetadata->is_contains_label) {
        word = strtok(line_copy, " ");
        word = strtok(NULL, " ");

    } else
        word = strtok(line_copy, " ");

    int temp_dc = labelSection->dc;
    word = strtok(NULL, ",");

    while (word != NULL) {
        word = trim_white_spaces(word);
        long number = string_to_number(word);
        char *converted_string = convert_number_to_binary_string(number);
        if (number == NULL) { //in case the input is not a valid number
            lineAndMetadata->is_error_occurred = 1;
            add_error_code(lineAndMetadata, ERR_CODE_INVALID_DATA_TYPE);
            return NULL;
        } else {
            labelSection->data_array[temp_dc] = converted_string;
        }
        temp_dc++;
        word = strtok(NULL, ",");
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
    int *counter_and_type = calloc(10, sizeof(int));
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
    char *line_copy = malloc(sizeof(char) * strlen(line) + 1);
    strcpy(line_copy, line);

    char *first_word = strtok(line_copy, " ");
    first_word = trim_white_spaces(first_word);
    char *last_char = &first_word[strlen(first_word) - 1];

    //  free(line_copy);

    if (!strcmp(last_char, ":")) {//strcmp returns 0 if the 2 strings equals
        first_word[strlen(first_word) - 1] = '\0'; //remove the ":" from the word.
        return first_word;
    } else
        return NULL;

    free(line_copy);
}

//checks if its data line , if so return the data type (".struct",".data",".string", etc'), else return null.
int get_data_instruction(struct LineAndMetadata *lineAndMetadata) {

    char *line_copy = malloc(sizeof(char) * strlen(lineAndMetadata->line));
    strcpy(line_copy, lineAndMetadata->line);


    if (lineAndMetadata->is_contains_label) {//if the line contains label the instruction_type word may be the second
        char *word = strtok(line_copy, " ");
        word = strtok(NULL, " ");
        word = trim_white_spaces(word);
        int data_type = ht_search(get_data_instruction_map(), word);
        if (data_type != NULL)
            return data_type; //find the instruction_type in the instruction_type table. if not exist return NULL
        else return NULL;
    } else {
        char *word = strtok(line_copy, " ");
        word = trim_white_spaces(word);
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
    } else return true;
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
    int operand_number = atoi(ht_search(get_opcode_and_amount_of_operands_map(), lineAndMetadata->opcode_type));
    Operands *operands = get_operands_and_type(lineAndMetadata);
    bool is_operand_valid = verify_operands(operands, operand_number, lineAndMetadata);

    if (!is_operand_valid) {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_OPERANDS);
        return NULL;
    }
    insert_opcode_line_to_image(lineAndMetadata, labelSection, operands);
    free(operands);

}


void free_operand(Operands *operands) {
    free(operands->source_operand);
    free(operands->destination_operand);
    free(operands);

}


void *insert_opcode_line_to_image(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection,
                                  Operands *operands) {
    int temp_ic = labelSection->ic; //use temporary index and update the ic only if the operation done properly.
    int first_line = calculate_first_line(operands, lineAndMetadata);
    char *first_line_converted = convert_number_to_binary_string(first_line);
    first_line_converted = first_line_converted + 1; //trim the leading 1
    labelSection->instruction_array[temp_ic] = first_line_converted;
    temp_ic++;



    //handle the source operand
    if (operands->source_operand_type == DIRECT_OFFSET_ADDRESSING_OPERAND) {
        char *temp = malloc(sizeof(char) * strlen(operands->source_operand));
        strcpy(temp, operands->source_operand);
        temp[strlen(temp) - 2] = '\0'; //trim the struct number.

        labelSection->instruction_array[temp_ic] = temp;
//        free(temp);

        temp_ic++;
        char num = operands->source_operand[strlen(operands->source_operand) -
                                            1]; //get the number of the struct operand 1/2

        // the following lines are for cast the char into char*
        //-----------------------------------------------------
        char *pNum;
        pNum = malloc(sizeof(char) * 2);
        *pNum = num;
        pNum[1] = '\0';
        //-----------------------------------------------------

        int line = 1; //normalize the line  //TODO: remember to subtract 1024 before the convert to binary
        line = line << 8;
        line += atoi(pNum);
        line = line << 2;
        char *converted_line = convert_number_to_binary_string(line);
        converted_line += 1;//delete the first 1
        labelSection->instruction_array[temp_ic] = converted_line;
        temp_ic++;

    } else if (operands->source_operand_type == REGISTER_ADDRESSING_OPERAND) {
        char num = ((char *) operands->source_operand)[strlen(operands->source_operand) - 1];
        int line = 1; //normalize the line  //TODO: remember to subtract 1024 before the convert to binary
        line = line << 8;
        // the following lines are for cast the char into char*
        //-----------------------------------------------------
        char *pNum;
        pNum = malloc(sizeof(char) * 2);
        *pNum = num;
        pNum[1] = '\0';
        //-----------------------------------------------------

        line += atoi(pNum);
        line = line << 2;
        char *converted_line = convert_number_to_binary_string(line);
        converted_line += 1;//delete the first 1
        labelSection->instruction_array[temp_ic] = converted_line;
        temp_ic++;
    } else if (operands->source_operand_type == IMMEDIATE_ADDRESSING_OPERAND) {
        char *num = operands->source_operand;
        num = num + 1; //remove the # prefix.
        int converted_number = atoi(num);
        int line = 1;//normalize the line  //TODO: remember to subtract 1024 before the convert to binary
        line = line << 11;
        line += converted_number;
        char *converted_line = convert_number_to_binary_string(line);
        converted_line += 1;//delete the first 1
        labelSection->instruction_array[temp_ic] = converted_line;
        temp_ic++;
    } else if (operands->source_operand_type == DIRECT_ADDRESSING_OPERAND) {
        labelSection->instruction_array[temp_ic] = operands->source_operand;
        temp_ic++;
    }

    //handle the destination operand
    if (operands->destination_operand_type == DIRECT_OFFSET_ADDRESSING_OPERAND) {
        char *temp = malloc(sizeof(char) * strlen(operands->source_operand));
        strcpy(temp, operands->source_operand);
        temp[strlen(temp) - 2] = '\0'; //trim the struct number.

        labelSection->instruction_array[temp_ic] = temp;
//        free(temp);

        temp_ic++;
        char num = ((char *) operands->destination_operand)[strlen(operands->source_operand) -
                                                            1]; //get the number of the operand 1/2.
        int line = 1; //normalize the line  //TODO: remember to subtract 1024 before the convert to binary
        line = line << 8;
        // the following lines are for cast the char into char*
        //-----------------------------------------------------
        char *pNum;
        pNum = malloc(sizeof(char) * 2);
        *pNum = num;
        pNum[1] = '\0';
        //-----------------------------------------------------
        line += atoi(pNum);
        line = line << 2;
        char *converted_line = convert_number_to_binary_string(line);
        converted_line += 1;//delete the first 1
        labelSection->instruction_array[temp_ic] = converted_line;
    } else if (operands->destination_operand_type == REGISTER_ADDRESSING_OPERAND) {
        char num = ((char *) operands->destination_operand)[strlen(operands->destination_operand) - 1];
        int line = 1; //normalize the line  //TODO: remember to subtract 1024 before the convert to binary
        line = line << 8;

        // the following lines are for cast the char into char*
        //-----------------------------------------------------
        char *pNum;
        pNum = malloc(sizeof(char) * 2);
        *pNum = num;
        pNum[1] = '\0';
        //-----------------------------------------------------

        line += atoi(pNum);
        line = line << 2;
        char *converted_line = convert_number_to_binary_string(line);
        converted_line += 1;//delete the first 1
        labelSection->instruction_array[temp_ic] = converted_line;
    } else if (operands->source_operand_type == IMMEDIATE_ADDRESSING_OPERAND) {
        char *num = operands->source_operand;
        num = num + 1; //remove the # prefix.
        int converted_number = atoi(num);
        int line = 1;//normalize the line  //TODO: remember to subtract 1024 before the convert to binary
        line = line << 8;
        line += converted_number;
        line = line << 2;
        char *converted_line = convert_number_to_binary_string(line);
        converted_line += 1;//delete the first 1
        labelSection->instruction_array[temp_ic] = converted_line;
    } else if (operands->destination_operand_type == DIRECT_ADDRESSING_OPERAND) {
        labelSection->instruction_array[temp_ic] = operands->destination_operand;
        temp_ic++;
    }
    labelSection->ic = temp_ic;

}

int calculate_first_line(Operands *operands, struct LineAndMetadata *lineAndMetadata) {
    int line_sum = 1; //normalize the line to keep the preceding zeros. while tranformation to binary remove the first 1.
    int operand_code = atoi(ht_search(get_opcode_and_decimal_map(), lineAndMetadata->opcode_type));
    line_sum = line_sum << 4; //move the operation code to be the 4  greater bits.
    line_sum += operand_code; //add the operand code to the line sum.

    int source_code_type = operands->source_operand_type;
    line_sum = line_sum << 2;
    if (source_code_type != -1) {
        line_sum += source_code_type;
    }

    line_sum = line_sum << 2;
    int dest_code_type = operands->destination_operand_type;
    if (dest_code_type != -1) {
        line_sum += dest_code_type;
    }
    line_sum = line_sum << 2;
    return line_sum;

}


Operands *get_operands_and_type(struct LineAndMetadata *lineAndMetadata) {
    Operands *operands = malloc(sizeof(Operands));
    char *line_copy = malloc(sizeof(char) * strlen(lineAndMetadata->line));
    strcpy(line_copy, lineAndMetadata->line);

    if (lineAndMetadata->is_contains_label) { //first normalize the pointer. if the line contains label the opcode word may be the second
        strtok(line_copy, " ");
        strtok(NULL, " ");
    } else
        strtok(line_copy, " ");

    char *temp = trim_white_spaces(strtok(NULL, ",")); //NULL if no operand
    if (temp == NULL || temp == '\0' || !strcmp(temp, ""))
        operands->source_operand = NULL;
    else
        operands->source_operand = temp;

    temp = trim_white_spaces(strtok(NULL, ","));//NULL if no operands/only 1 operand.
    if (temp == NULL || temp == '\0' || !strcmp(temp, ""))
        operands->destination_operand = NULL;
    else
        operands->destination_operand = temp;


    operands->source_operand_type = classified_operands(operands->source_operand);
    operands->destination_operand_type = classified_operands(operands->destination_operand);


    return operands;

}

bool verify_operands(Operands *operands, int operand_number, struct LineAndMetadata *lineAndMetadata) {
    bool amount = verify_operand_amount(operands, operand_number);
    if (!amount) {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_OPERANDS_AMOUNT);
    }

    bool syntax = verify_operands_syntax(operands, operand_number);
    if (!syntax) {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_OPERANDS_SYNTAX);
    }

    bool type = verify_operand_type(operands, lineAndMetadata);
    if (!type) {
        lineAndMetadata->is_error_occurred = 1;
        add_error_code(lineAndMetadata, ERR_CODE_INVALID_OPERANDS_TYPE);
    }


    return amount && syntax && type;


}

bool verify_operand_type(Operands *operands, struct LineAndMetadata *lineAndMetadata) {
    char *valid_addressing_source = ht_search(get_valid_source_addressing_map(), lineAndMetadata->opcode_type);
    char *valid_addressing_dest = ht_search(get_valid_dest_addressing_map(), lineAndMetadata->opcode_type);

    bool is_all_valid = true; //just set first to true if any is invalid then changed.

    if (valid_addressing_source != NULL && operands->source_operand_type != NULL) {
        char source_type = operands->source_operand_type +
                           '0'; //cast int to char BE AWARE! only works because the type is less than 10.
        char *pSource_type = malloc(2);
        *pSource_type = source_type;
        pSource_type[1] = '\0';
        if (!strstr(valid_addressing_source, pSource_type))
            is_all_valid = false;
    }

    if (valid_addressing_dest != NULL && operands->destination_operand_type != -1) {
        char *dest_type = operands->destination_operand_type +
                          '0'; //cast int to char BE AWARE! only works because the type is less than 10.
        char *pDest_type = malloc(2);
        *pDest_type = dest_type;
        pDest_type[1] = '\0';
        if (!strstr(valid_addressing_source, pDest_type))
            is_all_valid = false;
    }

    return is_all_valid;

}

bool verify_operand_amount(Operands *operands, int operand_number) {
    int current_operands = 0;

    if (operands->destination_operand != NULL)
        current_operands++;
    if (operands->source_operand != NULL)
        current_operands++;

    if (current_operands != operand_number)
        return false;
    else
        return true;
}


bool verify_operands_syntax(Operands *operands, int operand_number) {

    if (operands->source_operand != NULL && operands->source_operand_type == -1)
        return false;
    else if (operands->destination_operand != NULL && operands->destination_operand_type == -1)
        return false;
    else return true;
}


int classified_operands(char *operand) {
    if (operand == NULL)
        return -1;

    char first_char = *operand;
    if (first_char == '#')
        return IMMEDIATE_ADDRESSING_OPERAND;
    else if (ht_search(get_registers_map(), operand) != NULL)
        return REGISTER_ADDRESSING_OPERAND;
    else if (isalpha(first_char)) {
        char a = operand[strlen(operand) - 2];
        if (operand[strlen(operand) - 2] == '.' &&
            (operand[strlen(operand) - 1] == '1' ||
             operand[strlen(operand) - 1] == '2')) //in case this is strcut type operand (AB.1 for instance)
            return DIRECT_OFFSET_ADDRESSING_OPERAND;
        else
            return DIRECT_ADDRESSING_OPERAND;
    }

    return -1;

}

void *handle_operation(struct LineAndMetadata *lineAndMetadata, struct LabelSection *labelSection) {
    if (lineAndMetadata->is_contains_label) {
        insert_opcode_label_into_table(labelSection, lineAndMetadata);
    }
    validate_and_insert_opcode_line(lineAndMetadata, labelSection);

}

