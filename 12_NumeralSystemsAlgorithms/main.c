#include <stdio.h>

// Show (or not) prefix for numeral literals
#define PREFIX 1

/* Print a list of numbers in Decimal,
 * Octal and Hexadeximal numeral systems, using
 * ajust lgorithms, instead of printf() format.
 */
 
// These recursive functions convert from decimal to other
// numeral systems and then print the value on console.
void printOct(int);
void printHex(int);
void printBin(int);

int main(void) {
	// Print header
	printf("Dec\tOct\tHex\tBin\n");
	
	// Print table
	int i;
	for(i = 0; i <= 32; i++) {
		printf("%i\t", i);
		
		// Octal
		if(PREFIX)
			printf("0");
			
		printOct(i);
		printf("\t");
		
		// Hexadecimal
		if(PREFIX)
			printf("0x");
			
		printHex(i);
		printf("\t");
		
		// Binary
		if(PREFIX)
			printf("0b");
		
		printBin(i);
		printf("\t");
		
		printf("\n");
	}
	
	return 0;
}

// Print decimal number as octal
void printOct(int number)
{	
	if(number > 0 && number / 8 != 0)
		printOct(number / 8);
	
	printf("%i", number % 8);
}

// Print decimal number as hexadecimal
void printHex(int number)
{
	if(number > 0 && number / 16 != 0)
		printOct(number / 16);
	
	char digit;
	switch(number % 16) {
		case 10:
			digit = 'A';
			break;
		case 11:
			digit = 'B';
			break;
		case 12:
			digit = 'C';
			break;
		case 13:
			digit = 'D';
			break;
		case 14:
			digit = 'E';
			break;
		case 15:
			digit = 'F';
			break;
		default:
			digit = (char)((int)'0' + number % 16);
			break;
	}
	
	// Print digit
	printf("%c", digit);
}

// Print decimal number as binary
void printBin(int number)
{	
	if(number > 0 && number / 2 != 0)
		printBin(number / 2);
	
	printf("%i", number % 2);
}
