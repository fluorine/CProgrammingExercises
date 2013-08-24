#include <stdio.h>

/* Using pointers. */

int main() {
	
	// Declare integer and pointer
	int i = 7;   printf("int i = 7;\n");
	int *pi;     printf("int *pi;\n");
	pi = &i;     printf("pi = &i;\n");
	             printf("\n");
	
	// Show contents
	printf("  i\t-> %i\n",   i);    // Show variable
	printf("  *pi\t-> %i\n", *pi);  // Show pointed content of i
	printf("  &pi\t-> %x\n", pi);   // Show memory direction
	printf("\n");
	
	// Modify pointer
	int k = 40;  printf("int k = 40;\n");
	pi = &k;     printf("pi = &k;\n");
	             printf("\n");
	
	// Show modified contents
	printf("  i\t-> %i\n",   i);    // Show variable i
	printf("  k\t-> %i\n",   k);    // Show variable k
	printf("  *pi\t-> %i\n", *pi);  // Show pointed content of pi
	printf("  &pi\t-> %x\n", pi);   // Show memory direction
	printf("\n");
	
	return 0;
}
