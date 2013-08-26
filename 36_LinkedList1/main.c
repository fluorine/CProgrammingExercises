#include <stdio.h>

/* This little application uses structures and pointers
 * to implement a simple linked list of characters.
 */

// Linked list node
struct node {
	char value;
	struct node *next;
};

int main(void) {
	// Defining and linking nodes
	struct node n1, n2, n3;
	
	n1.value = 'G';
	n1.next  = &n2;
	
	n2.value = 'O';
	n2.next  = &n3;
	
	n3.value = 'D';
	n3.next  = (struct node *) 0;   // Null link
	                                // (to mark the end)
	
	// Show linked list's values until the end
	struct node *i = &n1;
	while(i != (struct node *) 0)
	{
		printf("%c ", i->value);
		i = i->next;
	}
		
	printf("\n");
	
	return 0;
}
