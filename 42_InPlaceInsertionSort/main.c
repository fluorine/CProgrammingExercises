#include <stdio.h>

/* Sorting an array using Insertion Sort O(n^2) */

void printArray(int[], int);
void insertionsort(int[], int);

int main() {
	// Array to sort
	int items[] = {3, 8, 9, 1, 0, 2, 4, 5, 6, 7};
	
	// Print original array
	printf("Original array: ");
	printArray(items, 10);
	
	// Sorting array
	insertionsort(items, 10);
	
	// Print sorted array
	printf("Sorted array:   ");
	printArray(items, 10);
	
	return 0;
}

// Insertion sort algorithm
void insertionsort(int items[], int size)
{
	int i;
	for(i = 1; i < size; i++)
	{
		int pos = i, item = items[i];
		
		// Get position
		while(pos > 0 && item < items[pos - 1])
			pos--;
		
		// Shift items to the right
		int k = i;
		while(k > pos)
		{
			items[k] = items[k - 1];
			k--;
		}
		
		// Put item
		items[pos] = item;
	}
}

// Print given array on console
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
