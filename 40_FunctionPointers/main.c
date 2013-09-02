#include <stdio.h>

/* This little application uses the C features
 * of pointers to functions with two integers
 * as arguments and an integer as a return value.
 */
 
// Some sample operations
int addition(int a, int b)
{
	return a + b;
}
 
int substraction(int a, int b)
{
	return a - b;
}
 
int product(int a, int b)
{
	return a * b;
}
 
int division(int a, int b)
{
	return a / b;
}

int modulus(int a, int b)
{
	return a % b;
}
 
// Structure to save an operation:
//   - name
//   - function
struct BinaryOperation {
	// A name for the operation
	char name[30];
	
	// The pointer, which a function
	// with two integers as arguments
	//and an integer as return value.
	int (*operation) (int, int);
};

// Entry point
int main(void) {
	// Number of functions (operations) to be considered
	 const int OperationsQty = 5;
	
	// Create an array of BinaryOperation structures.
	// Each entry has a name and a pointer to a function
	// with two int's as arguments and an int as return.
	struct BinaryOperation ops[] = {
		{"Addition",      addition},
		{"Substraction",  substraction},
		{"Product",       product},
		{"Division",      division},
		{"Modulus",       modulus}
	};
	
	// Show arguments
	int a = 12;
	int b = 3;
	printf("Arguments: %i, %i\n\n", a, b);
	
	// Show entries
	int i;
	for(i = 0; i < OperationsQty; i++)
		printf("  %15s -> %i\n", ops[i].name, ops[i].operation(a, b));
			
	return 0;
}
