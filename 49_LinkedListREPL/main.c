#include <stdio.h>
#include <stdlib.h>

/* This little application generates a linked list
 * of integers at runtime.
 *
 * This application is an example of the use of
 * dynamic memory allocation.
 */
 
// Struct for linked list's nodes
struct LinkedNode {
	int value;
	struct LinkedNode *next;
};

// Functions for linked lists
void printLinkedList(struct LinkedNode *);
void insertNode(struct LinkedNode *, int);

int main() {
	// Root of linked list
	struct LinkedNode *root = (struct LinkedNode *) 0;
	
	// Print instructions
	printf(" Insert an integer and press enter to insert it\n");
	printf(" in the Linked List. Insert a negative integer\n");
	printf(" to show the current Linked List.\n");
	
	// REPL
	int input;
	while(1) {
		// Prompt
		printf(" > ");
		
		if(scanf("%i", &input) != 1)
			continue;
		
		if(input < 0) {
			// Print linked list
			printLinkedList(root);
		} else {
			// Add integer into linked list
			if(root == NULL) {
				// Start a new linked list: allocate memory
				// for starting node and then initialize it
				root = (struct LinkedNode *)
				        malloc(sizeof(struct LinkedNode));
				 root->value = input;
				 root->next =  NULL;
			} else {
				// Insert item into existing linked list
				insertNode(root, input);
			}
		}
	}
	
	return 0;
}

void printLinkedList(struct LinkedNode *node) {
	printf(" [");
	
	// Iterate linked list
	while(node != NULL) {
		printf("%i ", node->value);
		node = node->next;
	}
		
	printf("]\n\n");
}

// Recursive function to insert new node
// at the end of the provided linked list
void insertNode(struct LinkedNode *list, int input) {
	if(list->next == NULL) {
		// Allocate dynamic memoty for a new node
		struct LinkedNode *temp =
		   (struct LinkedNode *)malloc(sizeof(struct LinkedNode));
		
		// Initialize new node
		temp->value = input;
		temp->next =  NULL;
		
		// Add new note into provided list
		list->next = temp;
	} else {
		// Go to the next node, recursively
		insertNode(list->next, input);
	}
}
