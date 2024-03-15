#include <stdio.h>
#include <string.h>
#include "entries.h"
#include "file_writer.h"

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

	/*for(int i=0; i<ARRAY_SIZE; i++) {
		if(existingWord[i] == 1)
			printf("in array %s\n", entries[i].word);
	}
	
	// printf("%s\n", wordFind);*/

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


int add(struct ENTRY* entries, int* numEntries) {
	printf("word: ");
	clearBuf();

	char new_word[LENGTH_SIZE];
	fgets(new_word, sizeof(new_word), stdin);
	// printf("%s", new_word);

	int pos = wordSearch(entries, new_word);
	if(pos!=-1) {
		printf("Word already exists! Please choose the edit function\n");
		return 1;
	}

	pos = emptySpotFinder(existingWord);
	if(pos==-1) {
		printf("Can't find an empty spot! Memory full :-(\n");
		return 1;
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

	printf("%s added", new_word);
	writeFile("entries.txt", entries, *numEntries);
	return 0;
}

int edit(struct ENTRY* entries, int numEntries) {
	int choice;
	char newWord[LENGTH_SIZE];
	char newSpeech[LENGTH_SIZE];
	char newTense[LENGTH_SIZE];
	char newDef[LENGTH_SIZE];

	char editRef[LENGTH_SIZE];
	int pos = wordSearch(entries, editRef);

	printf("word to edit: ");
    fgets(editRef, sizeof(editRef), stdin);

	if(pos != -1) {
		printf("Editing entry for %s\n", editRef);
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
		printf("Word is changed from %s to %s", entries[pos].word, newWord);
		strcpy(entries[pos].word, newWord);
		printf("Entry updated successfully!\n");
	} 
	if (choice == 2) {
        printf("Enter new part of speech: \n");                          
		clearBuf();                                                                   
		fgets(newSpeech, sizeof(newSpeech), stdin);                                   
		//strcpy(entries[0].word, newWord);                                           
		printf("Part of speech is changed from %s to %s", entries[pos].parts_of_speech, newSpeech);
        strcpy(entries[pos].parts_of_speech, newSpeech);
		printf("Entry updated successfully!\n");
      } 
	  if (choice == 3) {
          printf("Enter new tense: \n");                                                    
		  clearBuf();                                                                      
		  fgets(newTense, sizeof(newTense), stdin);
		  //strcpy(entries[0].word, newWord); 
		  printf("Tense is changed from %s to %s", entries[pos].tense, newTense);
          strcpy(entries[pos].tense, newTense);
		  printf("Entry updated successfully!\n");
      } 
	  if (choice == 4) {
          printf("Enter new definition: \n");                                               
		  clearBuf();                                                                      
		  fgets(newDef, sizeof(newDef), stdin);                                          
		  //strcpy(entries[0].word, newWord);                                              
		  printf("Word is changed from %s to %s", entries[pos].definition, newDef);
          strcpy(entries[pos].definition, newDef);
		  printf("Entry updated successfully!\n");
      }
	  writeFile("entries.txt", entries, numEntries);
	  return 0;
	}
	else {
		printf("Entry for %s is not found!", editRef);
		return 1;
	}
}

int erase(struct ENTRY* entries, int numEntries) {
	char wordToDelete[LENGTH_SIZE];
	int pos = wordSearch(entries, wordToDelete);
	printf("Word to delete: ");
	fgets(wordToDelete, sizeof(wordToDelete), stdin);
	clearBuf();
	if(pos != -1) {
		existingWord[pos] = -1;
		memset(&entries[pos], 0, sizeof(struct ENTRY));
		printf("Entry deleted successfully!");
		return 0;
		writeFile("entries.txt", entries, numEntries);
	}
	return 1;
}

void bubbleSort(struct ENTRY* entries, int* numEntries) {
	int i, j;
	for (int i = 0; i < *numEntries; i++) {
		for (int j = 0; j < *numEntries; j++) {
			if(strcmp(entries[j].word, entries[j+1].word) > 0) {
				struct ENTRY temp = entries[j];
				entries[j] = entries[j+1];
				entries[j+1] = temp;
			}
		}
	}

}

int display(struct ENTRY* entries, int numEntries) {
	bubbleSort(entries, &numEntries); // Sort the entries before displaying
    
    printf("+-------------------------+\n");
    printf("| %-20s | %-20s | %-20s | %-20s |\n", "Word", "Parts of Speech", "Tense", "Definition");
    printf("+-------------------------+\n");
    
    for (int i = 0; i < numEntries; i++) {
        printf("| %-20s | %-20s | %-20s | %-20s |\n", entries[i].word, entries[i].parts_of_speech, entries[i].tense, entries[i].definition);
    }
    
    printf("+-------------------------+\n");
	return 0;
	writeFile("entries.txt", entries, numEntries);
}
