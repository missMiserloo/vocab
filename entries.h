#ifndef ENTRIES_H
#define ENTRIES_H

#define ARRAY_SIZE 100 // how many words
#define LENGTH_SIZE 100 // how many letters                           
struct ENTRY {                                  
	char word[LENGTH_SIZE];
	char parts_of_speech[LENGTH_SIZE];
	char tense[LENGTH_SIZE];
	char definition[LENGTH_SIZE];
};
#endif
