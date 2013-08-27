#include <stdio.h>

/* This little application uses structures and pointers
 * to implement a simple linked list of characters.
 * It also uses pointers as arguments and return values.
 *
 * This applications implements a function for finding
 * items in a linked list.
 */

// Linked list node
struct node {
	char value;
	struct node *next;
};

struct node *findNode(struct node *, char);
void showLinkedList(struct node *);

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
	printf("Linked list: ");
	showLinkedList(&n1);
	
	// REPL to find items in the linked list
	char target;
	struct node *found;
	while(1)
	{
		printf("\nItem to find in list: ");
		target = getchar();
		getchar();
		
		found = findNode(&n1, target);
		
		if(found == (struct node *) 0)
			printf("   Value NOT found.\n");
		else
			printf("   Value '%c' was FOUND.\n", target);
	}
	
	return 0;
}

// This function returns a pointer to the node of
// the linked list that contains the target value.
// It returns null node, if value was not found at
// the linked list.
struct node *findNode(struct node *lstStart, char target)
{
	if(lstStart == (struct node *) 0)
	{
		return (struct node *) 0;
	} else {
		if(lstStart->value == target)
			return lstStart;
		else
			return findNode(lstStart->next, target);
	}
}

// Show linked list on console
void showLinkedList(struct node *i)
{
	while(i != (struct node *) 0)
	{
		printf("%c ", i->value);
		i = i->next;
	}

	printf("\n");
}
