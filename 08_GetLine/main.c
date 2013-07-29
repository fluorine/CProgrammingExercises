#include <stdio.h>

/* Read line to show it */

#define MAXLENGTH 80

int getline(char line[], int lim);

main()
{
	char line[MAXLENGTH];
	getline(line, MAXLENGTH);
	printf("%s", line);
	return 0;
}

/* Get a string (char array) from console, save it
 * in given argument, and then return the length. */
int getline(char line[], int lim)
{
	int c, i;
	for(i = 0; i < lim - 1
	      && (c = getchar()) != '\n'
		  && c != EOF; ++i)
		line[i] = c;
	
	if(c == '\n')
		line[i++] = c;
	
	line[i] = '\0';
	return i;
}

