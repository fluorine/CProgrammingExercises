#include <stdio.h>

/* This program implements the Binary Search Algorithm
 * to find a number in an array of integers.
 *
 * The program also counts the number of steps that
 * were required to find the number.
 */
 
 #define ARRAYSIZE 12
 
int compareTo(int, int);
int showArray(int[], int);
int find(int, int[], int);
int binarySearch(int, int[], int, int);

// Counter of steps in the binary search algorithm
int gAlgorithmStepsCounter;

int main() {
	int numbers[] = {1, 2, 4, 5, 7, 8, 11, 15, 17, 33, 40, 45};
	printf("Array to find a number in: ");
	showArray(numbers, ARRAYSIZE);
	printf("\n");
	
	int i, index;
	while(1)
	{
		printf("> ");
		scanf("%i", &i);
		
		// Find number
		index = find(i, numbers, ARRAYSIZE);
		if(index != -1)
			printf("  Number %i found at %i. (%i steps)\n\n",
			       i, index, gAlgorithmStepsCounter);
		else
			printf("  Number %i was NOT found. (%i steps)\n\n",
			       i, gAlgorithmStepsCounter);
	}
	
	return 0;
}

// This method uses the Binary Search Algorithm
// to look for a number in the given array.
int find(int target, int numbers[], int size)
{
	// Reset counter for Binary Search steps
	gAlgorithmStepsCounter = 0;
	
	return binarySearch(target, numbers, 0, size);
}

// Implementation of the Recursive Binary Search algorithm
int binarySearch(int target, int numbers[],
                 int start, int limit)
{
	// Counting algorithm stepts
	gAlgorithmStepsCounter++;
	
	// Recursive Binary Search algorithm	
	if(limit - start < 1)
		return -1;
	else {
		int mid = start + (limit - start) / 2;
		
		switch(compareTo(target, numbers[mid]))
		{
			case 1:
				return binarySearch(target, numbers, mid + 1, limit);
			case -1:
				return binarySearch(target, numbers, start, mid);
			default:
				return mid;
		}
	}
} 

// Show array of integer on Console
int showArray(int numbers[], int size)
{
	int i;
	for(i = 0; i < size; i++)
		printf(" %i", numbers[i]);
	
	printf("\n");
}

// Compare two integers
//    Returns -1, if a < b
//    Returns  1, if a > b
//    Returns  0, if a == b
int compareTo(int a, int b)
{
	if(a < b)
		return -1;
	else if(a > b)
		return 1;
	else
		return 0;
}
