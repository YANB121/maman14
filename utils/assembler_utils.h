
#ifndef MAMN14_ASSEMBLER_UTILS_H
#define MAMN14_ASSEMBLER_UTILS_H

#include "hashmap.h"

struct SymbolsSection {
    int dc;
    int ic;
    HashTable *symbol_table;
};

struct SymbolEntry {
    char *type; // type of data/code
    int counter;// the relevant counter value (ic/dc)
};


struct SymbolsSection *initialize_symbol_section();

#endif //MAMN14_ASSEMBLER_UTILS_H
