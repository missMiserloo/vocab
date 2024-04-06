#ifndef UTILS_H
#define UTILS_H

int add(struct ENTRY* entries);
int edit(struct ENTRY* entries);
int erase(struct ENTRY* entries);
int display(struct ENTRY* entries);
void initializeExistingWord();

void writeFile(const char* filename, struct ENTRY* entries);
void readFile(const char* filename, struct ENTRY* entries);

#endif // !DEBUG
