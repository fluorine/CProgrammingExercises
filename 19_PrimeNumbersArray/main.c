#include <stdio.h>
#include <stdbool.h>

/* Fill array with prime numbers, */

bool isPrime(int);

int main(void)
{
	int i, n, count;
	
	// Ask for how many prime numbers
	printf("How many prime numbers? ");
	scanf("%i", &n);
	
	// Check conditions
	if(n < 0)
	{
		printf("\n\n  A minimum of one prime number is required.\n");
		return 0;
	}
	
	// Generate n prime numbers
	count = 0;
	int prime[n];
	
	for(i = 2; count < n; ++i)
	{
		if(isPrime(i))
			prime[count++] = i;
	}
	
	// Print array of prime numbers
	printf("\n\n");
	for(i = 0; i < n; ++i)
		printf("%i ", prime[i]);
	
	return 0;
}

// Check is given numbers is prime.
bool isPrime(int n)
{
	int i;
	for(i = 3; i < n; i++)
		if(n % i == 0)
			return false;
	
	return true;
}
