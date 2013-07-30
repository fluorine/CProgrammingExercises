#include <stdio.h>

// maximum characters for input
#define MAXLENGTH 200

// Boolean values
typedef enum { false, true } bool;

/* Remove all C comments from an input string. */

bool is_balanced(char line[], int lim);
void remove_comments(char from[], char to[], int lim);

int main() {
	char  input[MAXLENGTH];
	char output[MAXLENGTH];
	
	// Get input
	printf("Input:  ");
	getline(input, MAXLENGTH);
	
	// Remove comments
	remove_comments(input, output, MAXLENGTH);
	
	// Show without comments
	printf("Output: ");
	printf("%s", output);
	
	return 0;
}

// Remove both line and block comments
void remove_comments(char from[], char to[], int lim)
{
	bool on_line_comment  = false;
	bool on_block_comment = false;
	
	int i_to = 0;
	int i_from = 0;
	
	// Input string traversal
	while(from[i_from] != '\0' && i_from < lim - 1)
	{
		if(on_line_comment)
		{
			// Detect end of comment line
			if(from[i_from++] == '\n')
				on_line_comment = false;
				
		} else if(on_block_comment) {
			// Detect end of block comment
			if(from[i_from] == '*' && from[i_from + 1] == '/')
			{
				i_from++;
				on_block_comment = false;
			}
			
			i_from++;
		} else {
			// Catch start of comments
			if(from[i_from] == '/' && from[i_from + 1] == '/') {
				i_from += 2;
				on_line_comment = true;
				continue;
			} else if(from[i_from] == '/' && from[i_from + 1] == '*') {
				i_from += 2;
				on_block_comment = true;
				continue;
			} 
			
			
			to[i_to++] = from[i_from++];
		}
	}
	to[i_to] = '\0';
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
