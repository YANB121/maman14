
#include "assembler_utils.h"

struct LabelSection *initialize_label_section() {
    int ic = 0;
    int dc = 0;
    HashTable *symbols_table;

    struct LabelSection *symbolsSection = malloc(sizeof(struct LabelSection));
    symbolsSection->dc = dc;
    symbolsSection->ic = ic;
    symbolsSection->label_table = symbols_table;

    return symbolsSection;
}

