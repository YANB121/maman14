#ifndef MAMN14_ASSEMBLER_UTILS_H
#define MAMN14_ASSEMBLER_UTILS_H

#include "hashmap.h"

struct LabelSection {
    int dc;
    int ic;
    HashTable *label_table;

};

struct LabelEntry {
    int *type; // type of data/code
    int counter;// the relevant counter value (ic/dc)
};

struct LabelSection *initialize_label_section();

#endif //MAMN14_ASSEMBLER_UTILS_H
