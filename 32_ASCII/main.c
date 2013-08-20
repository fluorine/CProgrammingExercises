#include <stdio.h>

/* Show simple table of ASCII characters */

int main(int argc, char *argv[]) {
	// Header
	printf("     ASCII table\n\n");
	
	// Body
	char i, j;
	for(i = 'a', j = 'A'; i < 'z'; i++, j++)
		printf("%c = %3i     %c = %3i\n", i, i, j, j);
	
	return 0;
}
