#include <stdio.h>
#include <stdbool.h>

/* This program is able to find in a string
 * using a RECURSIVE algorithm.
 */

int strFind(char[], char[]);
int recursiveStrFind(char[], char[], int, int, int);

int main() {
	char text[80], substring[80];
	int i;
	
	// Input text to find in
	printf("Text to find in: ");
	gets(text);
	printf("\n");
	
	// Search substring
	while(true)
	{
		printf("> ");
		gets(substring);
		
		i = strFind(substring, text);
		if(i != -1)
			printf("Substring '%s' found at index %i.\n\n", substring, i);
		else
			printf("Substring '%s' NOT found in text.\n\n", substring);
	}
	
	return 0;
}

// Find a substring in a given string, using recursion
int strFind(char sub[], char text[])
{
	return recursiveStrFind(sub, text, 0, 0, -1);
}

// Recursive implementation of algorithm to find substring 
int recursiveStrFind(char sub[], char text[],
                     int isub,   int itext,   int start)
{
	// Check for end of text or substring
	if(text[itext] == '\0' || sub[isub] == '\0') {
		return start;
	} else if(text[itext] == sub[isub]) {
		if(start < 0) // Save index, if start of substring
			return recursiveStrFind(sub, text, isub + 1, itext + 1, itext);
		else          // Continuation of substring?
			return recursiveStrFind(sub, text, isub + 1, itext + 1, start);
	} else {
		// If current itext character doesn't match isub character.
		// go to next itext index.
		return recursiveStrFind(sub, text, 0, itext + 1, -1);
	}
	
}
