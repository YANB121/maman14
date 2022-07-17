
#include "assembler_utils.h"

struct SymbolsSection *initialize_symbol_section() {
    int ic = 0;
    int dc = 0;
    HashTable *symbols_table;

    struct SymbolsSection *symbolsSection = malloc(sizeof(symbolsSection));
    symbolsSection->dc = dc;
    symbolsSection->ic = ic;
    symbolsSection->symbol_table = symbols_table;

    return symbolsSection;
}

