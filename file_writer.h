#ifndef FILE_WRITER_H
#define FILE_WRITER_H
#include <stdio.h>
#include "entries.h"

void writeFile(const char* filename, struct ENTRY* entries, int numEntries);

#endif // FILE_WRITER_H
