#include <stdio.h>
#include <string.h>
#include "entries.h"
#include "input.h"

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
	my_gets(new_word, sizeof(new_word));
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
		my_gets(entries[pos].tense, sizeof(entries[0].tense));
	}
	else clearBuf();
	printf("definition: ");
	my_gets(entries[pos].definition, sizeof(entries[0].definition));
	strcpy(entries[pos].word, new_word);

	existingWord[pos] = 1;

	printf("%s added", new_word);
	//writeFile("entries.txt", entries, *numEntries);
	return 0;
}

int edit(struct ENTRY* entries, int numEntries) {
	int choice;
	char newWord[LENGTH_SIZE];
	char newSpeech[LENGTH_SIZE];
	char newTense[LENGTH_SIZE];
	char newDef[LENGTH_SIZE];

	char editRef[LENGTH_SIZE];

	printf("word to edit: ");
	clearBuf();
    my_gets(editRef, sizeof(editRef));
	int pos = wordSearch(entries, editRef);

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
		my_gets(newWord, sizeof(newWord));
		//strcpy(entries[0].word, newWord);
		printf("Word is changed from %s to %s", entries[pos].word, newWord);
		strcpy(entries[pos].word, newWord);
		printf("Entry updated successfully!\n");
	} 
	if (choice == 2) {
        printf("Enter new part of speech: \n");                          
		clearBuf();                                                                   
		my_gets(newSpeech, sizeof(newSpeech));                                   
		//strcpy(entries[0].word, newWord);                                           
		printf("Part of speech is changed from %s to %s", entries[pos].parts_of_speech, newSpeech);
        strcpy(entries[pos].parts_of_speech, newSpeech);
		printf("Entry updated successfully!\n");
      } 
	  if (choice == 3) {
          printf("Enter new tense: \n");                                                    
		  clearBuf();                                                                      
		  my_gets(newTense, sizeof(newTense));
		  //strcpy(entries[0].word, newWord); 
		  printf("Tense is changed from %s to %s", entries[pos].tense, newTense);
          strcpy(entries[pos].tense, newTense);
		  printf("Entry updated successfully!\n");
      } 
	  if (choice == 4) {
          printf("Enter new definition: \n");                                               
		  clearBuf();                                                                      
		  my_gets(newDef, sizeof(newDef));                                          
		  //strcpy(entries[0].word, newWord);                                              
		  printf("Word is changed from %s to %s", entries[pos].definition, newDef);
          strcpy(entries[pos].definition, newDef);
		  printf("Entry updated successfully!\n");
      }
	  //writeFile("entries.txt", entries, numEntries);
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
	my_gets(wordToDelete, sizeof(wordToDelete));
	clearBuf();
	if(pos != -1) {
		existingWord[pos] = -1;
		memset(&entries[pos], 0, sizeof(struct ENTRY));
		printf("Entry deleted successfully!");
		return 0;
		//writeFile("entries.txt", entries, numEntries);
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

int display(struct ENTRY* entries) {
	//bubbleSort(entries, &numEntries); // Sort the entries before displaying
	
    printf("+-------------------------+\n");
    printf("| %-20s | %-20s | %-20s | %-20s |\n", "Word", "Parts of Speech", "Tense", "Definition");
    printf("+-------------------------+\n");
    
    for (int i = 0; i < ARRAY_SIZE; i++) {
		if(existingWord[i]!=-1)
        	printf("| %-20s | %-20s | %-20s | %-20s |\n", entries[i].word, entries[i].parts_of_speech, entries[i].tense, entries[i].definition);
    }
    
    printf("+-------------------------+\n");
	return 0;
	//writeFile("entries.txt", entries, numEntries);
}

void writeFile(const char* filename, struct ENTRY* entries) {
    FILE* file = fopen(filename, "w");
    if (file) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
			if(existingWord[i]!=-1){
            	fprintf(file, "Word: %s\n", entries[i].word);
            	fprintf(file, "Parts of Speech: %s\n", entries[i].parts_of_speech);
            	fprintf(file, "Tense: %s\n", entries[i].tense);
            	fprintf(file, "Definition: %s\n", entries[i].definition);
            	fprintf(file, "+-------------------------+\n");
			}
        }
        fclose(file);
    } else {
        printf("Error opening file for writing.\n");
    }
}

void readFile(const char* filename, struct ENTRY* entries) {
    FILE* file = fopen(filename, "r");
	if(file==NULL) {
		printf("File not fount, write will create a new one at the end\n");
		return;
	}
	int i=0;
	int j;
	char c;
	// scan word
	do {
		while((c=fgetc(file))!=':' && c!=EOF)
			continue;

		if(c==EOF)
			break;

		fgetc(file);
		
		j = 0;
		while((c=fgetc(file))!='\n'){
			entries[i].word[j] = c;
			j++;
		}
		entries[i].word[j] = '\0';

		// scan parts of speech
		while((c=fgetc(file))!=':')
    	    continue;
		fgetc(file);
		j = 0;
		while((c=fgetc(file))!='\n'){
			entries[i].parts_of_speech[j] = c;
			j++;
		}
		entries[i].parts_of_speech[j] = '\0';

		// scan tense
		while((c=fgetc(file))!=':')
    	    continue;
		fgetc(file);
		j = 0;
		while((c=fgetc(file))!='\n'){
			entries[i].tense[j] = c;
			j++;
		}
		entries[i].tense[j] = '\0';

		// scan definition
		while((c=fgetc(file))!=':')
    	    continue;
		fgetc(file);
		j = 0;
		while((c=fgetc(file))!='\n'){
			entries[i].definition[j] = c;
			j++;
		}
		entries[i].definition[j] = '\0';
		existingWord[i] = 1;
		i++;

		// scan +----------------+ 
		while((c=fgetc(file))!='\n')
			continue;
	} while (1);
	
    fclose(file);
}
