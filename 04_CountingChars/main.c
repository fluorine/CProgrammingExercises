#include <stdio.h>
/* Counting characters from a "stream" */

main()
{
	long nc;
	nc = 0;
	while(getchar() != EOF)
		++nc;
	
	printf("%ld\n", nc);
}
