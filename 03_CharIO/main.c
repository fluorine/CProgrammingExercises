#include <stdio.h>

/* Read and then print characters. */

main()
{
	printf("EOF: %c\n", EOF);
	int c;
	while((c = getchar()) != EOF)
		putchar(c);
}
