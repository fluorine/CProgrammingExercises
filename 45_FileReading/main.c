#include <stdio.h>

/* Reading a text file from local directory. */

int main(void) {
	// String variable to save input file
	char fileName[80];
	
	// Get file name
	printf("Write name of file to open: ");
	scanf("%s", fileName);
	printf("\n");
	
	// Printing input file's name
	printf("Content of \"%s\":\n", fileName);
	
	// Opening file for reading
	FILE *inputFile;
	inputFile = fopen(fileName, "r");
	
	// Printing file content
	if(inputFile == NULL) {
		printf("Error opening file.\n");
		return 1;
	} else {
		// Print content of input file
		int c; do {
			c = getc(inputFile);
			putchar(c);
		} while(c != EOF);
	}
	
	return 0;
}
