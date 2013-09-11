#include <stdio.h>
#include <stdbool.h>

// Include conversion factors 
#include "metric.h"

/* This program converts an input number (for inches or miles)
 * into centimeters or miles. 
 *
 * This application shows the use of header files.
 */

int main(void) {
	// REPL
	double input;
	while(true)
	{
		printf("Insert a value for inches or miles: ");
		scanf("%lf", &input);
		printf("  -> %.3f cm in %.3f inches\n", input * CM_IN_INCH, input);
		printf("  -> %.3f km in %.3f miles\n\n", input * KM_IN_MILE, input);
	}
	
	return 0;
}
