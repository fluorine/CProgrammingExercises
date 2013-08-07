#include <stdio.h>

/* This little application contains a function
 * to calculate factorials.
 *
 * The recursive function to calculate factorial
 * values uses TAIL recursion.
 */

unsigned long long int fact(int);
unsigned long long int tailFact(int, unsigned long long int);

int main() {
	int i;
	for(i = 0; i <= 15; i++)
		printf("%i\t%llu\n", i, fact(i));
		
	return 0;
}

// Calculate factorials

unsigned long long int
fact(int n)
{
	if(n < 0)
		return 0;
	else
		return tailFact(n, 1);
}

unsigned long long int
tailFact(int n, unsigned long long int accum)
{
	if(n <= 0)
		return accum;
	else
		return tailFact(n - 1, accum * n);
}
