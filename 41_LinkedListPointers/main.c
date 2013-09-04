#include <stdio.h>

/* Using pointers and linked lists. */

// Node for linked list of integers
struct node {
	int value;
	struct node *next;
};

// Methods for linked lists
void printList(struct node *);
struct node insertNode(int, struct node *);

int main(void) {
	struct node n0 = insertNode(7, (struct node *) 0);
	struct node n1 = insertNode(6, &n0);
	struct node n2 = insertNode(5, &n1);
	struct node n3 = insertNode(4, &n2);
	struct node n4 = insertNode(3, &n3);
	struct node n5 = insertNode(2, &n4);
	struct node n6 = insertNode(1, &n5);
	struct node n7 = insertNode(0, &n6);
	
	printList(&n7);
	printf("End.");
	
	return 0;
}

// Print linked list on Console
void printList(struct node *lst)
{
	if(lst == (struct node *) 0)
	{
		printf("\n");
	} else {
		printf(" %i", lst->value);
		printList(lst->next);
	}
}

// Add node to the start of the linked list
struct node insertNode(int value, struct node *lst)
{
	return (struct node) {value, lst};
}
