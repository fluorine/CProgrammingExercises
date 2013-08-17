#include <stdio.h>
#include <stdbool.h>

#define LINESIZELIMIT 81

/* This program reads a line of text from terminal
 * and then counts how many words are there.
 */

int main() {
	int countWords(char[]);	
	char line[LINESIZELIMIT];
	
	printf("Write a line of text to count its words.\n");
	
	while(true)
	{
		printf("> ");
		gets(line);
		printf("\n  There are %i words.\n\n", countWords(line));
	}
	
	return 0;
}

// Count how many words are in
// the given array of characters.
int countWords(char line[])
{
	bool isAlphabetic(char);
	bool onWord = false;
	int  wordsCount = 0, i;
	
	for(i = 0; i < LINESIZELIMIT - 1 && line[i] != '\0'; i++)
	{
		bool isLetter = isAlphabetic(line[i]);
		
		if(isLetter && !onWord)
		{
			onWord = true;
			wordsCount++;
		} else if(!isLetter && onWord) {
			onWord = false;
		}
	}
	
	return wordsCount;
}

// Check if given character is a letter
bool isAlphabetic(char c)
{
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return true;
	else
		return false;
}
