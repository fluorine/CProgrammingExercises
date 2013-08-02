#include <stdio.h>
#include <stdbool.h>

/* This program takes any integer
 * and shows its digits reversed.
 *
 * Leading zeroes don't appear. */
int reversed(int, int);

int main() {
	while(true)
	{
		printf("Write a number to reverse\nits digits: ");
		int input;
		scanf("%i", &input);
		
		// Quit if negative number
		if(input < 0)
			break;
		
		printf("\n  Reversed digits: %i\n\n", reversed(input, 0));
	}
	
	return 0;
}

// Reverse the digits of a given number
int reversed(int in, int out)
{
	if(in <= 0)
		return out;
	
	return reversed(in / 10, (out * 10) + (in % 10));
}

