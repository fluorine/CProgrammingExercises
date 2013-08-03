#include <stdio.h>
/* This program takes some scores to caculate
 * the average, maximum and minimum.
 */

int main(void) {
	int qty, i;
	float score, sum, max, min;
	
	// Get quantity of scores
	printf("How many scores will you provide? ");
	scanf("%i", &qty);
	printf("\n");
	
	// Get scores from user
	for(i = 0; i < qty; i++)
	{
		printf("  #%i = ", i + 1);
		scanf("%f", &score);
		
		// Initialize variables
		// with first value.
		if(i == 0) {
			max = min = sum = score;
		} else {
			if(score > max)
				max = score;
			
			if(score < min)
				min = score;
			
			sum += score;
		}		
	}
	
	// Show quantity
	printf("\n  Quantity: %i\n", qty);
	
	// Show total
	printf("  Total:    %.2f\n\n", sum);
	
	// Show average
	printf("  Average:  %.2f\n", (float)sum / qty);
	
	// Show maximum
	printf("  Maximum:  %.2f\n", max);
	
	// Show minimum
	printf("  Minimum:  %.2f\n", min);
	
	return 0;
}
