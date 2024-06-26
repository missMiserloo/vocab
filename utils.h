#ifndef UTILS_H
#define UTILS_H

int add(struct ENTRY* entries, int languageChoice);
int edit(struct ENTRY* entries, int languageChoice);
int erase(struct ENTRY* entries, int languageChoice);
int display(struct ENTRY* entries, int languageChoice);
void initializeExistingWord();

void writeFile(const char* filename, struct ENTRY* entries);
void readFile(const char* filename, struct ENTRY* entries);

#endif // !DEBUG
