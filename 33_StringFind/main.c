#include <stdio.h>
#include <stdbool.h>

/* This program is able to find in a string. */

int strFind(char[], char[]);

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

// Find a substring in a given string, using iteration
int strFind(char sub[], char text[])
{
	// Substring not found, if substring is null
	if(sub[0] == '\b')
		return -1;
	
	// Search for the string in the text
	int start = 0, subi = 0;
	bool onSub = false;
	
	int i;
	for(i = 0; text[i] != '\0'; i++)
	{
		if(onSub)
		{
			// Find rest of substring (or its end)
			if(sub[subi] == '\0')
				return start;
			
			if(sub[subi++] != text[i])
				onSub = false;
				
		} else {
			// Find start of target substring
			// in text, and initialize variables
			if(sub[0] == text[i])
			{
				onSub = true;
				start = i;
				subi = 1;
			}
		}
	}
	
	return -1;
}
