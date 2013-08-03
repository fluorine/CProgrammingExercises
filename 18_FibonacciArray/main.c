#include <stdio.h>

/* This program populates a dynamic array
 * with the Fibonacci sequence.
 */

int main(void) {
	// Ask the user how many Fibonacci
	// values to produce.
	int n, i;
	printf("How many Fibonacci values to produce (2 to 75)?");
	scanf("%i", &n);
	
	// Check if valid number of values
	if(n < 2 || n > 75)
	{
		printf("\n  Invalid request.");
		return 1;
	}
	
	// Produce Fibonacci values
	unsigned long long int fibo[n];
	fibo[0] = 1;
	fibo[1] = 1;
	
	for(i = 2; i < n; ++i)
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	
	// Show produced values from array
	printf("\n");
	for(i = 0; i < n; i++)
		printf("%i ", fibo[i]);
	
	return 0;
}
