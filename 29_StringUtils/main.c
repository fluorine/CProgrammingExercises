#include <stdio.h>
#include <stdbool.h>

/* This program contains some useful functions
 * for arrays of characters (strings).
 */
 
int  strLength(const char[]);
void strConcat(const char[], const char[], char[]);
bool strEqual(char[], char[]);

int main(void)
{
	// Counting character of an array of character
	// until the \0 signal.
	char hola[20] = {'h', 'o', 'l', 'a', '\0'};
	printf("Count length of \"hola\" string in a char[20]:\n  %i\n\n",
	     strLength(hola));
	
	printf("Count length of \"Ahura Mazda\" string in a char[12]:\n  %i\n\n",
	     strLength("Ahura Mazda"));
	
	// Displaying string using %s
	printf("Display previous string using %%s:\n  %s\n\n", hola);
	
	// Concatenation of two strings
	char a[20] = "hola ";
	char b[]   = "mundo";
	char c[80];
	strConcat(a, b, c);
	printf("Concatenating \"hola \" and \"mundo\"\n  \"%s\"\n\n", c);
	
	// Chech equality of two strings
	char d[80] = "mundo";
	printf("Check if \"mundo\" [6] and \"mundo\" [80] are equal:\n  %s\n\n",
	       strEqual(b, d) ? "true" : "false");
	       
	printf("Check if \"hola\" [5] and \"holama\" [7] are equal:\n  %s\n\n",
	       strEqual("hola", "holama") ? "true" : "false");
	       
	printf("Check if \"Jesus\" [6] and \"Muhammad\" [9] are equal:\n  %s\n\n",
	       strEqual("Jesus", "Muhammad") ? "true" : "false");
	       
	return 0;
}

// Counting characters before null \0 signal
//   -> Argument is marked as 'const' because it's
//      not going to be modified in this function.
int strLength(const char str[])
{
	int count = 0;
	
	while(str[count] != '\0')
		count++;
		
	return count;
}

// Function for concatenation of two strings
void strConcat(const char input1[], const char input2[], char output[])
{
	// Index for output string
	int iout = 0;
	
	// Traversal of input1 string
	int i = 0;
	while(input1[i] != '\0')
		output[iout++] = input1[i++];
	
	// Traversal of input2 string 
	i = 0;
	while(input2[i] != '\0')
		output[iout++] = input2[i++];
	
	// Placing \0 at the end of output string
	output[iout] = '\0';
}

// Function to check if two strings are
// equivalent, before the null (\0) signal
bool strEqual(char a[], char b[])
{
	int i;
	for(i = 0; a[i] != '\0' && b[i] != '\0'; i++)
		if(a[i] != b[i])
			return false;
			
	// Check if both string end at the same index
	if(a[i] == b[i])
		return true;
	else
		return false;
}
