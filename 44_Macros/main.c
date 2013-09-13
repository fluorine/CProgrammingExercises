#include <stdio.h>

// Some macros
#define SQUARE(x) ((x) * (x))
#define SUM(a,b)  ((a) + (b))

/* This program uses preprocessor's macros
 * as replacements for functions.
 *
 * It is possible to use macros as a way to
 * ignore static types at compilation time.
 */

int main(void) {
	int   a = 5;
	float x = 3.1415926, y = 0.86;
	
	printf("SQUARE(%i) = %i\n", a, SQUARE(a));
	printf("SQUARE(%f) = %f\n", x, SQUARE(x));
	
	printf("SUM(%f, %f) = %f\n", x, y, SUM(x, y));
	printf("SUM(%i, %f) = %f\n", a, x, SUM(a,x));
	
	return 0;
}
