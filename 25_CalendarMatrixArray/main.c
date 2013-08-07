#include <stdio.h>

/* Fill a multidimensional array as calendar's month. */

void fillMonth(int[6][7], int, int);
void printMonth(int[6][7]);

int main()
{
	int month[6][7];
	
	// Show calendar for August 2013
	printf("     August 2013\n");
	fillMonth(month, 4, 31);
	printMonth(month);
	
    // Show calendar for January 2014
	printf("     January 2014\n");
	fillMonth(month, 6, 31);
	printMonth(month);
	
	return 0;
}

// Print the matrix in a calendar format.
void printMonth(int month[6][7])
{
	int i, k;
	for(i = 0; i < 6; i++)
	{
		for(k = 0; k < 7; k++)
		{
			if(month[i][k] > 0)
				printf("%3i", month[i][k]);
			else
				printf("   ");
		}
		printf("\n");
	}
			
}

// Fill matrix for month
void fillMonth(int month[6][7], // Field for month
               int start,       // Start column
               int days)        // Quantity of days
{
	int count, i, k;
	count = 1;
	start %= 7;
	
	for(i = 0; i < 6; i++)
		for(k = 0; k < 7; k++)
		{
			if(start <= 0 && count <= days) {
				month[i][k] = count++;
			} else {
				month[i][k] = 0;
				start--;
			}
		}
}
