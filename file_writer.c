#include <stdio.h>
#include "file_writer.h"
#include "entries.h"

void writeFile(const char* filename, struct ENTRY* entries, int numEntries) {
    FILE* file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < numEntries; i++) {
            fprintf(file, "Word: %s\n", entries[i].word);
            fprintf(file, "Parts of Speech: %s\n", entries[i].parts_of_speech);
            fprintf(file, "Tense: %s\n", entries[i].tense);
            fprintf(file, "Definition: %s\n", entries[i].definition);
            fprintf(file, "+-------------------------+\n");
        }
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
}

