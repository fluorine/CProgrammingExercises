#include <stdio.h>

/* Show a table or triangular numbers.
 * using iteration.
 */

int main() {
	// Show table's header
	printf("n\ttriangular number\n");
	// Show table
	int i;
	int sum = 0;
	for(i = 1; i <= 20; i++)
		printf("%i\t%i\n", i, sum += i);
	
	return 0;
}
