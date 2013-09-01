#include <stdio.h>

/* This program uses pointers and arrays of characters, or strings. */

void strCopy(char*, char*);

int main(void) {
	
	char original[] = "Hola mundo.";
	char copy[50];
	
	strCopy(&original, &copy);
	
	printf("Original: %s\nCopy:     %s\n", original, copy);
	
	return 0;
}

// This functions copies input string on output
void strCopy(char *input, char *output)
{
	while(*input != '\0')
		*output++ = *input++;
	
	output = '\0';
}
