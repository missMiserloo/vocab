#include <stdio.h>
#include "entries.h"
#include "utils.h"

extern struct ENTRY entries;

void optionMenu() {
	printf("\nChoose a setting:\n");
	printf(" 1. Add\n");
	printf(" 2. Edit\n");
	printf(" 3. Remove\n");
	printf(" 4. Display\n");
	printf(" 5. Back\n");
}
void languageMenu() {
	printf("\nKyrie's Word List\n\n");
	printf("Choose a language:\n");  
	printf(" 1. English\n");
	printf(" 2. French\n");
	printf(" 3. German\n");
	printf(" 4. Turkish\n");
	printf(" 5. Hindi\n");
	printf(" 6. Arabic\n");
	printf(" 7. Exit\n");
}

void optionChooser(int optionChoice) {
	switch(optionChoice) {
		case 1:
			printf("add selected\n");
			add(&entries);
			break;
		case 2:
            printf("edit selected\n");
			edit(&entries);
            break;
		case 3:
            printf("delete selected\n");
            break;
		case 4:
            printf("display selected\n");
            break;
		case 5:
            printf("Going back to language menu\n");
            break;
		default:
			printf("Invalid option. Please retry.\n");
			break;
	}
}
