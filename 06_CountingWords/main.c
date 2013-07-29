#include <stdio.h>
#include <stdlib.h>

/* An application for counting words from stream. */

#define TRUE  1
#define FALSE 0

main()
{
	//Variables for counting words
	int c, count, on_word;
	on_word = FALSE;
	count = 0;
	
	// Counting words
	while((c = getchar()) != '\n')
	{
		if(c == ' ' || c == '\t')
		{
			if(on_word)
				on_word = FALSE;
		} else {
			if(!on_word)
			{
				on_word = TRUE;
				++count;
			}
		}
	}
	
	// Show quantity of words
	printf("Words count: %d\n", count);
}
