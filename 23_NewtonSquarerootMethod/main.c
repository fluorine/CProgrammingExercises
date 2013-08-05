#include <stdio.h>

/* Approximate square root of a number
 * using the Newton-Raphson method.
 */
 
double abs(double n);
double newton(double, double);
double sqrt(double);

int main()
{
	double n, result;
	printf("Calculate square root of a number\n");
	
	while(1)
	{
		printf("> ");
		scanf("%lf", &n);
		result = sqrt(n);
		if(result > 0) 
			printf("  sqrt(%f) = %f\n\n", n, result);
	}
}

// Square root
double sqrt(double n)
{
	// Checking. No negative numbers are allowed
	if(n < 0)
	{
		printf("  Error. This application cannot calculate\n");
		printf("         square roots of negative numbers.\n\n");
		return -1;
	}
	
	// Using Newton-Raphson method
	// to calculate the square root.
	return newton(n, 1);
}

// Recursive implementation of the
// Newton-Raphson method.
double newton(double n, double guess)
{
	const double epsilon = 0.00001;
	
	if(abs(guess * guess - n) < epsilon)
		return guess;
	else
		return newton(n, (n / guess + guess) / 2);
}

// Return absolute value of a number
double abs(double n)
{
	if(n < 0)
		return -n;
	else
		return n;
 }
 
