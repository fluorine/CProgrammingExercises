#include <stdio.h>

/* Using a recursive implementation of the Euclid algorithm
 * to get the Greatest Common Divisor of two given numbers.
 */
 
int gcd(int, int);

int main(void) {
	// print instructions
	printf("Put two numbers (separated by space) to calculate\nthe Greatest Common Divisor: ");
	
	// get two numbers from user
	int i, j;
	scanf("%i%i", &i, &j);
	
	// get Great Common Divisor
	printf("\n  Greatest Common Divisor: %i\n", gcd(i, j));
	
	return 0;
}

// Calculate Great Common Divisor
// using the recursive Euclid Algorithm.
int gcd(int a, int b)
{
	if(b == 0)
		return a;
	
	return gcd(b, a % b);
}
