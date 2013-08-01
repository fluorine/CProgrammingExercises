#include <stdio.h>

/* Show a table or triangular numbers.
 * using recursion.
 *
 * This implementation is more elegant and clear,
 * yet it's not as efficient as the iterative version.
 */
 
int getTriangular(int);

int main() {
	// Show table's header
	printf("n\ttriangular number\n");
	// Show table
	int i;
	for(i = 1; i <= 20; i++)
		printf("%i\t%i\n", i, getTriangular(i));
	
	return 0;
}

// Recursive function to ger a triangular number
int getTriangular(int n)
{
	if(n < 1)
		return 0;
	else
		return n + getTriangular(n - 1);
}
