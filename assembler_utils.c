
#include <string.h>
#include "assembler_utils.h"
#include "hashmap.h"
#include "file_utils.h"
#include "constants.h"
#include "input_utils.h"


struct LabelSection *initialize_label_section() {
    int ic = 0;
    int dc = 0;
    HashTable *symbols_table = create_table(MAX_LABELS);


    struct LabelSection *symbolsSection = malloc(sizeof(struct LabelSection));
    symbolsSection->dc = dc;
    symbolsSection->ic = ic;
    symbolsSection->label_table = symbols_table;
    symbolsSection->entry_labels = create_table(MAX_LABELS);
    memset(symbolsSection->data_array, 0, MAX_PROGRAM_LENGTH * sizeof(int));
    memset(symbolsSection->instruction_array, 0, MAX_PROGRAM_LENGTH * sizeof(int));

    return symbolsSection;
}


void write_memory_image_to_object_file(char *program_path, struct LabelSection *labelSection) {
    //trim the ".am" extension and add ".o" extension
    char *output_file_name = get_name_with_new_file_extension(program_path, ".o", 3);
    //open new file for writing.
    FILE *output_file = open_write_file_else_exit(output_file_name);
    char *ic_as_32 = ten_bits_binary_to_32_decimal(convert_number_to_binary_string(labelSection->ic));
    char *dc_as_32 = ten_bits_binary_to_32_decimal(convert_number_to_binary_string(labelSection->dc));

    fputs(ic_as_32, output_file);
    fputs(" ", output_file);
    fputs(dc_as_32, output_file);
    fputs("\n", output_file);
    int i = 0;
    for (i = i; i < MAX_PROGRAM_LENGTH; i++) {
        if (labelSection->instruction_array[i] == NULL)
            break; //exit the loop when program ended
        char *line_base_32 = ten_bits_binary_to_32_decimal(labelSection->instruction_array[i]);
        char *addr = ten_bits_binary_to_32_decimal(convert_number_to_binary_string(i + 100) + 1);
        fputs(addr, output_file);
        fputs(" ", output_file);
        fputs(line_base_32, output_file);
        fputs("\n", output_file);
    }

    int j;
    for (j = i; j < MAX_PROGRAM_LENGTH; j++) {
        if (labelSection->data_array[j - i] == NULL)
            break; //exit the loop when program ended
        char *line_base_32 = ten_bits_binary_to_32_decimal(labelSection->data_array[j - i]);
        char *addr = ten_bits_binary_to_32_decimal(convert_number_to_binary_string(j + 100) + 1);
        fputs(addr, output_file);
        fputs(" ", output_file);
        fputs(line_base_32, output_file);
        fputs("\n", output_file);
    }


}

char *ten_bits_binary_to_32_decimal(char *binary_num) {
    char *first_5 = malloc(sizeof(char) * 5 + 1);
    memcpy(first_5, binary_num, 5);
    first_5[5] = '\0';


    char *second_5 = malloc(sizeof(char) * 5 + 1);
    for (int i = 5; i < 10; i++)
        second_5[i - 5] = binary_num[i];
    second_5[5] = '\0';

    char *result = malloc(sizeof(char) * 3);

    result[0] = ((char *) ht_search(get_binary_to_32_base_map(), first_5))[0];
    result[1] = ((char *) ht_search(get_binary_to_32_base_map(), second_5))[0];
    result[2] = '\0';
    return result;
}


void write_external_file(char *program_path, struct LabelSection *labelSection) {
    //trim the ".am" extension and add ".o" extension
    char *output_file_name = get_name_with_new_file_extension(program_path, ".ex", 3);
    //open new file for writing.
    FILE *output_file = open_write_file_else_exit(output_file_name);


    char **labels = get_keys(labelSection->label_table);
    for (int i = 0; i < MAX_LABELS; i++) {
        if (labels[i] == NULL)
            break;
        char *temp = labels[i];
        printf("%s", temp);
        int *label_arr = ht_search(labelSection->label_table, labels[i]);
        if (label_arr[0] == EXTERNAL_TYPE_LABEL)
            for (int j = 2; j < 10; j++) {
                if (label_arr[j] != 0) {
                    char *addr = ten_bits_binary_to_32_decimal(convert_number_to_binary_string(label_arr[j] + 100) + 1);
                    fputs(labels[i], output_file);
                    fputs(" ", output_file);
                    fputs(addr, output_file);
                    fputs("\n", output_file);
                }
            }

    }

}


void write_entry_file(char *program_path, struct LabelSection *labelSection) {
    //trim the ".am" extension and add ".o" extension
    char *output_file_name = get_name_with_new_file_extension(program_path, ".en", 3);
    //open new file for writing.
    FILE *output_file = open_write_file_else_exit(output_file_name);


    char **labels = get_keys(labelSection->entry_labels);
    for (int i = 0; i < MAX_LABELS; i++) {
        if (labels[i] == NULL)
            break;

        int *label_arr = ht_search(labelSection->label_table, labels[i]);
        char *addr = ten_bits_binary_to_32_decimal(convert_number_to_binary_string(label_arr[1] + 100) + 1);
        fputs(labels[i], output_file);
        fputs(" ", output_file);
        fputs(addr, output_file);
        fputs("\n", output_file);
    }
}







