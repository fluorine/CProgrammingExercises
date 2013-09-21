#include <stdio.h>

/* This utility allows the user to copy a file.*/

int main(void) {
	char  in[64],  out[64];   // File names
	FILE *inFile, *outFile;   // File instances
	
	// Define file names
	printf("Original file name: ");
	scanf("%63s", in);
	
	printf("Copy name: ");
	scanf("%63s", out);
	
	// Catch errors
	if((inFile = fopen(in, "r")) == NULL)
	{
		printf("Error when opening file to read.\n");
		return 1;
	}
	
	if((outFile = fopen(out, "w")) == NULL)
	{
		printf("Error when opening file to write.\n");
		return 2;
	}
	
	// Copying content
	int c; 
	while((c = getc(inFile)) != EOF)
		putc(c, outFile);
	
	//Close files
	fclose(inFile);
	fclose(outFile);
	
	return 0;
}
