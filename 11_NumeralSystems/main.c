#include <stdio.h>

/* This program shows a table of
 * numbers in three numeral systems,
 * using just printf() text arguments:
 *   - Decimal
 *   - Octal
 *   - Hexadecimal
 */

int main(void) {
	// Table header
	printf("Dex\tOct\tHex\n");
	
	// Show table
	int i;
	for(i = 0; i < 40; i++)
		printf("%i\t%#o\t%#x\n", i, i, i);
	
	return 0;
}
