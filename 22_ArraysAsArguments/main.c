#include <stdio.h>

/* This application contains some basic functions
 * that take arrays as arguments.
 */
 
// Print an array of integers on console
void printArray(int items[], int size)
{
	printf("[");
	
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%i", items[i]);
		
		// Separator of items
		if(i < size - 1)
			printf(" ");
	}
		
		
	printf("]\n");
}
 
// Get a minimum for arrays of 10 integers
int minTen(int items[10])
{
	int i, min = items[0];
	for(i = 1; i < 10; i++)
		if(items[i] < min)
			min = items[i];
			
	return min;
}

// Get minimum from array of any size
int min(int items[], int size)
{
	int i, min = items[0];
	for(i = 0; i < size; i++)
		if(items[i] < min)
			min = items[i];
			
	return min;
}

// Multiply each item from array
void multiplyEach(int number, int items[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		items[i] *= number;
}

int main()
{
	// Declaring array of 10 items
	int dek[] = {3, 9, 0, 7, -3, 6, 1, 2, 4, 5};
	
	//Show array of 10 items
	printf("Simple methods for array:\n");
	printf("  dek[10]      -> ");
	printArray(dek, 10);
	printf("  minTen(dek)  -> %i\n", minTen(dek));
	printf("  min(dek, 10) -> %i\n\n", min(dek, 10));
	
	// Modifying array
	printf("Modifying array 'dek'\n\n");
	printf("  Original ->\n    ");
	printArray(dek, 10);
	printf("\n  multiplyEach(2, dek, 10) ->\n    ");
	multiplyEach(2, dek, 10);
	printArray(dek, 10);
	
	return 0;
}
