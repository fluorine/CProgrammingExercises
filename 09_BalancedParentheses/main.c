#include <stdio.h>
#include <stdbool.h>

/* This program shows "true" if a given string contains
 * balanced parentheses, or "false" if otherwise:
 *     (())  -> "true"
 *     (()   -> "false"
 *     )(    -> "false"
 *     )()(  -> "false"
 *     )))   -> "false"
 */

#define MAXLENGTH 200

// Functions
int  get_line(char line[], int lim);
bool is_balanced(char line[], int lim);

main()
{
	char input[MAXLENGTH];
	
	// Get string
	printf(">");
	getline(input, MAXLENGTH);
	
	// Check if balanced
	if(is_balanced(input, MAXLENGTH))
		printf("True");
	else
		printf("False");
	
	return 0;
}

// Get a string from console
int getline(char line[], int lim)
{
	int c, i;
	for(i = 0; i < lim - 1
	      && (c = getchar()) != '\n'
		  &&  c != EOF; ++i)
		line[i] = c;
	
	if(c == '\n')
		line[i++] = c;
	
	line[i] = '\0';
	return i;
}

// Return TRUE (1) if parenthesis in line 
// are balanced or FALSE (0) otherwise.
bool is_balanced(char line[], int lim)
{
	int level = 0;
	int i;
	
	for(i = 0; i < lim && line[i] != '\0'; ++i)
	{
		// Return FALSE if level is negative,
		// since internal parenthesis are not balanced.
		if(level < 0)
			return false;
		
		// Increase or decrease level
		// for parentheses
		if(line[i] == '(')
			++level;
		
		if(line[i] == ')')
			--level;
	}
	
	// Return false if number of opening parentheses
	// doesn't match the number of closing parentheses.
	if(level != 0)
		return false;
		
	return true;
}
