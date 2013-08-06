#include <stdio.h>

/* Sorting an array using Selection Sort O(n^2) */

void printArray(int[], int);
void swap(int[], int, int);
void selectionsort(int[], int);

int main() {
	// Array to sort
	int items[] = {3, 8, 9, 1, 0, 2, 4, 5, 6, 7};
	
	// Print original array
	printf("Original array: ");
	printArray(items, 10);
	
	// Sorting array
	selectionsort(items, 10);
	
	// Print sorted array
	printf("Sorted array:   ");
	printArray(items, 10);
	
	return 0;
}

// Selection sort algorithm
void selectionsort(int items[], int size)
{
	int i, k;
	for(i = 0; i < size; i++)
		for(k = i + 1; k < size; k++)
			if(items[i] > items[k])
				swap(items, k, i);
}

// Swap two items in different arrays' slots
void swap(int items[], int x, int y)
{
	int temp = items[x];
	items[x] = items[y];
	items[y] = temp;
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
