#include <stdio.h>
#include <stdlib.h>

// kyrie learned to write a basic library
#include "menus.h"
#include "entries.h"
#include "utils.h"
#include "file_writer.h"

struct ENTRY entries[ARRAY_SIZE];
int numEntries = ARRAY_SIZE;

int main() {
	const char* filename = "entries.txt";
    writeFile(filename, &entries[0], numEntries);

    return 0;

	initializeExistingWord();

	int languageChoice;
	int optionChoice;
	int exitChoice = 7;

	do {
		languageMenu();
		printf("Choice: ");
		scanf("%d", &languageChoice);
		if (languageChoice < 1 || languageChoice > exitChoice) {
		printf("Invalid choice. Please retry.\n");
		} else if (languageChoice == exitChoice) {
            printf("Exiting the program.\n");
            exit(0);
        } else {
			printf("You chose language %d.\n", languageChoice);

			do {
				optionMenu();
				printf("Option: ");
				scanf("%d", &optionChoice);
				optionChooser(optionChoice);
			} while (optionChoice > 5);
		}
	} while (1);
	
	return 0;
}
