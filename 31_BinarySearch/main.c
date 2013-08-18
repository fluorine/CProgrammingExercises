#include <stdio.h>

/* This program implements the Binary Search Algorithm
 * to find a number in an array of integers.
 */
 
 #define ARRAYSIZE 12
 
int compareTo(int, int);
int showArray(int[], int);
int find(int, int[], int);
int binarySearch(int, int[], int, int);

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
			printf("  Number %i found at %i.\n\n", i, index);
		else
			printf("  Number %i was NOT found.\n\n", i);
	}
	
	return 0;
}

// This method uses the Binary Search Algorithm
// to look for a number in the given array.
int find(int target, int numbers[], int size)
{
	return binarySearch(target, numbers, 0, size);
}

// Implementation of the Recursive Binary Search algorithm
int binarySearch(int target, int numbers[],
                 int start, int limit)
{	
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
