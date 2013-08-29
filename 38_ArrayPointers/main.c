#include <stdio.h>

/* This program simply sums all integers from an array,
 * but using pointers arithmetic. */

int arraySum( int[], const int);

int main(void) {
	int numbers[] = {0, 1, 2, 3, 4, 5};   // -> 15
	
	printf("Sum array: 0 1 2 3 4 5\n\n");
	
	printf("Total: %i", arraySum(numbers, 6));
	
	return 0;
}

int arraySum(int arr[], const int size)
{
	int *pt, sum;
	
	for(pt = arr; pt < (arr + size); pt++)
		sum += *pt;
	
	return sum;
}
