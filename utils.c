#include <stdio.h>
#include <string.h>
#include "entries.h"

static int[] existingWord;

for (int i = 0; i < ARRAY_SIZE; i++)
	existingWord[i] = -1;

int wordSearch(struct ENTTRY* entries, char wordFind) {
	int count = -1;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (existingWord[i] == 1)
			if (strcmp(entries[i].word, wordFind) == 0) {
				count = i;
				break;
			}
		return count;
	}


int add(struct ENTRY* entries) {
	printf("word: ");
	getchar();
	fgets(entries[0].word, sizeof(entries[0].word), stdin);
	printf("parts of speech: ");
	scanf("%s", entries[0].parts_of_speech);
	if (strcmp(entries[0].parts_of_speech, "verb") == 0) {
		printf("tense: ");
		getchar();
		fgets(entries[0].tense, sizeof(entries[0].tense), stdin);
	}
	printf("definition: ");
	fgets(entries[0].definition, sizeof(entries[0].definition), stdin);
}

int edit(struct ENTRY* entries) {
	int choice;
	char newWord[LENGTH_SIZE];
	char newPOS[LENGTH_SIZE];
	char newTense[LENGTH_SIZE];
	char newDef[LENGTH_SIZE];

	printf("word to edit: ");
    scanf("%s", entries[0].word);
	printf("\nwhat to edit: \n");
	printf(" 1. Word\n");
	printf(" 2. Parts of speech\n");
	printf(" 3. Tense\n");
	printf(" 4. Definition\n");
	printf("choice: ");
	scanf("%d", &choice);

	if (choice == 1) {
		printf("Enter new word: \n");
		getchar();
		fgets(newWord, sizeof(newWord), stdin);
		//strcpy(entries[0].word, newWord);
		printf("Word is changed from %s to %s", entries[0].word, newWord);
		strcpy(entries[0].word, newWord);
	}
	

}

int erase(struct ENTRY* entries) {

}

int display(struct ENTRY* entries) {

}
