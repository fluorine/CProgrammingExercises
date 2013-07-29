#include <stdio.h>

/* Print a Fahrenheit-Celsius table */

//Constants
#define LOWER 0
#define UPPER 300
#define STEP  20
main()
{
	//Show table's header 
	printf("Fahrenheit to Celsius table\n");
	
	//Show table values
	int fahr, celsius;
	for(fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
}
