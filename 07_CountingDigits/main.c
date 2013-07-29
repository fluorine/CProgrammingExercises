#include <stdio.h>

/* This programm takes a string of digits
 * from the console and counts how many of
 * each digit are there. */

main()
{
	// Declare and initialize array of counters
	// for each digit.
	int digits[10];
	int i, c;
	for(i = 0; i < 10; i++)
		digits[i] = 0;
	
	// Take input of characters for digits
	printf("Count digits from input stream (Enter to end)\n>");
	while((c = getchar()) != '\n')
	{
		if(c >= '0' && c <= '9')
			++digits[c - '0'];
		
		//Ignores no-digit characters
	}
	
	// Print header for array of counters
	for(i = 0; i < 10; i++)
		printf(" %d", i);
	
	printf("\n");
	
	// Print array of counters
	for(i = 0; i < 10; i++)
		printf(" %d", digits[i]);	
}
