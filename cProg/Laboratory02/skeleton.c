#include <stdio.h>		// needed for printf(), malloc(), etc
#include <stdlib.h>		// needed for exit()
#include "dbg.h"		// needed for log_err and others
#define NDEBUG			// use the debug macros

#define NAME_LENGTH 20 	// The maximum # characters in a name 
						// our program will handle (hint: use 
						// this with malloc)

/* Define a "node" structure which contains a string
   for the name, an age (integer) and a pointer to 
   another node structure. This will point to the next
   node in the linked list. We use a typedef so we can
   succinctly refer to it as node_t. */
typedef struct node {
	int age;
	char* name;
	struct node *next;
} node_t;

/* function declartions */
node_t * node_create();
node_t * list_append(node_t * head);
node_t * list_remove(node_t * head);
node_t * list_insert(node_t * head);
void list_destroy(node_t * head);
void print_list(node_t * head);
void count_list(node_t * head);
void node_destroy(node_t * p);

int main(int argc, char * argv[])
{
	/* declare the head of the linked list and 
	   a char to store the users selection after
	   the prompt */
	struct node *head;
	char selection = 0;


	/* When the program starts, it should query the user 
	   for the name and age of a person, and use this information 
	   to create the first node of the list. "head" is a pointer 
	   to the head node. Store the values entered by the user
	   for the name and age into head. */
	head = node_create();
	printf("  Begin the list by typing a name followed by age: ");
	// YOUR CODE HERE to get use input and store in head


	/* We use an infinite while loop to repeatedly ask the user
	   for input. If the user types 'q', we exit the program */
	while(1){
		
		/* Prompt the user for a selected action and store the
		   choice in char selection */
		printf("\n  What would you like to do?\n  (a) add a node to the head of list\n  (i) insert a node in the middle of the list\n  (l) display the length of the list\n  (r) remove a node from the list\n  (p) print the list\n  (q) quit\n");
		scanf(" %c", &selection);

		/* use a switch to handle the various choices */
		switch ((char) selection) {
			case 'a':
				head = list_append(head);
				print_list(head);
				break;

			case 'i':
				head = list_insert(head);
				print_list(head);
				break;

			case 'p':
				print_list(head);
				break;

			case 'l':
				count_list(head);
				break;

			case 'r':
				head = list_remove(head);
				print_list(head);
				break;

			case 'q':
				list_destroy(head);
				exit(0);
				break;	

			default:
				/* if we don not see an input we recognize, 
				   loop around and request again */
				printf("Unrecognized selection: %c, try again.\n", selection);
				break;
				
		}
	}
	return 0;
}


/* A function to create a new node structure and allocate memory 
   from the heap. It returns a node_t* p pointer to the new node.
   Creating the node requires 2 memory allocations, one for the
   structure (node_t) and one for the character array node_t.name */
node_t * node_create() 
{
    node_t *p;
    // YOUR CODE HERE: allocate memory for the node_t structure and
    // the name string field. Set the "next" pointer. Do an 
    // error-check to make sure the memory is allocated if(p == NULL) ...

    return p;
}

/* A function to destroy an existing node and return memory to the
   operating system */
void node_destroy(node_t * p) 
{
	if(p == NULL) log_err("Error tried to destroy a null pointer");
	// YOUR CODE HERE: release the memory for this node

}

/* A function print all the names and ages in the linked list. It
   takes a pointer to the head node as an argument and loops 
   through all nodes in the linked list, prints the name and age 
   of each as it goes. It stops once it reaches the end of the list
   (NULL pointer) */
void print_list(node_t * head) {
    node_t * p = head;
    // YOUR CODE HERE: print the contents of the linked list in the
    // format shown in the instructions
}

/* A function count how many nodes appear in the linked list.
   It takes a pointer to the head node as an argument and
   loops through all the nodes in the linked list, keeping
   count of how many it has traversed. Once it reaches
   the end of the linked list (NULL pointer) it prints
   the total number of nodes in the list */
void count_list(node_t * head) {
	// YOUR CODE HERE: count the number of elements in the linked list
	// and print the result to the terminal, as shown in the 
	// instructions
}

/* A function to add a new node to the head of the linked list.
   It takes a pointer to the head node as an argument, then
   queries the user for the name and age. It calls node_create()
   to create the node, then fills the new node with the collected
   data. Finally it points the new node to the old head of the list
   and returns the new node as the new head of the linked list. */
node_t * list_append(node_t * head)
{
	node_t *p;

	p = node_create();
	printf("  Type name followed by age: ");
	scanf("%s %d", p->name, &p->age);
	p->next = head;
	head = p;
	return head;
}

/* A function that removes a node from the list. It takes the
   head of the list and returns a new head of the list. It prompts 
   the user to type the index he/she wants to remove and stores the 
   index. If the index is 0, the head node is destroyed and head->next 
   becomes the new head. If another index is specified a loop is used
   to set the pointer *prev to the node previous to index we want to 
   destroy. We assign p to prev->next. 
   We then attach the link from prev->next to prev->next->next. 
   Finally we destroy p. */
node_t * list_remove(node_t * head) {

	node_t *prev;		// the node before the one we want to remove
	node_t *p;			// the node we want to remove
	int index;			// the node index we want to remove
	int i = 0;

	printf("  Type the index you want to remove: ");
	scanf(" %d", &index);

	if (index == 0)						// remove the head if index == 0
	{
		p = head;
		head = head->next;
		node_destroy(p);
	} else {							// otherwise, remove p 
		prev = head;
		for (i = 1; i < index; i++) {	// loop until *prev is index before *p
   			prev = prev->next;
   			if(prev == NULL) log_err("NULL pointer, index must be out of bounds");
			}
		//printf("  removing i = %d, name = %s\n", i, prev->next->name);
		p = prev->next;					// get a pointer to *p which we want to destroy
		prev->next = p->next;			// connect prev->next to p->next
		node_destroy(p);
	}
    return head;
}

/* A function that inserts a node into the linked list. It takes the
   head of the list and returns a new head of the list. It prompts 
   the user to type the index he/she wants to insert to and stores the 
   index. It calls node_create() to create the node, then fills the 
   new node with the collected data. If the index is 0, the new node
   becomes the head node. If another index is specified a loop is used
   to set the pointer *prev to the node previous to index we want to 
   insert at. We then assign p->next to prev->next, and p to prev->next.  */
node_t * list_insert(node_t * head) {
	// YOUR CODE HERE: write the function to insert a node at a user
	// requested index. Follow the example in the instructions. 
}

/* A function to destroy the entire linked list. It is given a pointer to the
   head of the list, then iterates through the list, destroying each node
   it goes (freeing memory) */
void list_destroy(node_t * head) {
    node_t * p; 	// the node we will destroy
    node_t * q;		// the next node in the list
    p = head;
    int i = 0;

    while (p != NULL) {
    	q = p->next;
    	printf("%d. %s (%d) DESTROYED!\n", i, p->name, p->age);
    	node_destroy(p);
        p = q;
        i++;
    }
}