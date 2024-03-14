#include <stdio.h>
#include <string.h>
#include "entries.h"

static int existingWord[ARRAY_SIZE];

void clearBuf() {
	while(getchar()!='\n');
}

void initializeExistingWord() {
for (int i = 0; i < ARRAY_SIZE; i++)
	existingWord[i] = -1;
}

int wordSearch(struct ENTRY* entries, char* wordFind) {
	int count = -1;

	for(int i=0; i<ARRAY_SIZE; i++) {
		if(existingWord[i] == 1)
			printf("in array %s\n", entries[i].word);
	}
	
	printf("%s\n", wordFind);

	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (existingWord[i] == 1 && strcmp(entries[i].word, wordFind) == 0) {
				count = i;
				break;
			}
		}
	return count;
}

int emptySpotFinder(int existingWord[]) {
	for(int i=0; i<ARRAY_SIZE; i++) {
		if(existingWord[i]==-1)
			return i;
	}
	return -1;
} 


int add(struct ENTRY* entries) {
	printf("word: ");
	clearBuf();

	char new_word[LENGTH_SIZE];
	fgets(new_word, sizeof(new_word), stdin);
	printf("%s", new_word);

	int pos = wordSearch(entries, new_word);
	if(pos!=-1) {
		printf("Word already exists! Please choose the edit function\n");
		return -1;
	}

	pos = emptySpotFinder(existingWord);
	if(pos==-1) {
		printf("Can't find an empty spot! Memory full :-(\n");
		return -1;
	}

	printf("parts of speech: ");
	scanf("%s", entries[pos].parts_of_speech);
	if (strcmp(entries[pos].parts_of_speech, "verb") == 0) {
		printf("tense: ");
		clearBuf();
		fgets(entries[pos].tense, sizeof(entries[0].tense), stdin);
	}
	else clearBuf();
	printf("definition: ");
	fgets(entries[pos].definition, sizeof(entries[0].definition), stdin);
	strcpy(entries[pos].word, new_word);

	existingWord[pos] = 1;
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
		clearBuf();
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
