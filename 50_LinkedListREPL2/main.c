#include <stdio.h>
#include <stdlib.h>

/* This little application uses a REPL to generate 
 * a linked list of integers at runtime. This version
 * allows the user to delete items.
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
void   printLinkedList(struct LinkedNode *);
struct LinkedNode *insertNode(struct LinkedNode *, int);
struct LinkedNode *deleteNode(struct LinkedNode *, int);

int main() {
	// Root of linked list
	struct LinkedNode *root = NULL;
	
	// Print instructions
	printf(" Insert an integer and press enter to insert it in\n");
	printf(" the Linked List. Insert zero to show the full list.\n");
	printf(" Insert number as negative to delete the positive\n");
	printf(" equivalent from the list.\n");
	
	// REPL
	int input;
	while(1) {
		// Prompt
		printf(" > ");
		
		if(scanf("%i", &input) != 1)
			continue;
		
		if(input > 0) {
			// Add integer into linked list
			root = insertNode(root, input);
		} else if (input < 0){
			// Delete item from linked list
			root = deleteNode(root, -input);
		} else {
			// Print linked list
			printLinkedList(root);
		}
	}
	
	return 0;
}

// Print linked list's content at console
void printLinkedList(struct LinkedNode *node) {
	printf(" [");
	
	// Iterate linked list
	while(node != NULL) {
		printf("%i ", node->value);
		node = node->next;
	}
		
	printf("]\n\n");
}

// Insert new node into the head of the provided Linked List
// and return a pointer to rhe new start of the linked list.
struct LinkedNode *insertNode(struct LinkedNode *list, int input) {
	// Create new node
	struct LinkedNode *temp = 
	   (struct LinkedNode *)malloc(sizeof(struct LinkedNode));
	
	// Initialize new node, link list next to it
	// and finally return pointer to it.
	temp->value = input;
	temp->next = list;
	
	return temp;
}

// Remove node from provided Linked List and
// return a pointer to start of the list, using recursion
struct LinkedNode *deleteNode(struct LinkedNode *list, int input) {
	if(list == NULL) {
		return list;
	} else {
		if(list->value == input) {
			// Free current pointer
			struct LinkedNode *temp = list->next;
			free(list);
			return temp;
		} else {
			list->next = deleteNode(list->next, input);
			return list;
		}
	}
}
