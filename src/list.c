//#include <stdio.h>


	//write a pair of functions list_add() & list_remove()


	//function adds an element to a linked list
    void list_add(struct list_element *list_head, struct list_element *new_element) {
	if (new_element == NULL) {
	   return;  //dont add NULL elements
	}
	if (*list_head == NULL) {	//if list is empty, add new element as head
	   *list_head = new_element;
	   new_element->next = NULL;
	} else {
	   //non-empty list
	   struct list_element *current = *list_head;		//create current element
	   //traverse to end of list
	   while (current->next != NULL) {
		current = current->next;
	   }

	   //add new element at end
	   current->next = new_element;
	   new_element->next = NULL;
	}
    }

	//function removes element from linked list
    void list_remove(struct list_element *element) {
	if (*list_head == NULL || element == NULL) {
	   return;	//list or element empty
	}
	//list not empty, create current & prev elements
	struct list_element *current = *list_head;
	struct list_element *prev = NULL;
	//if element to be removed is head
	if (current == element) {
	   *list_head = current->next;	//allocate head to next element
	   free(current);	//free up memory that was allocated for current
	   return;
	}

	//traverse the list to find element
	while (current != NULL && current != element) {
	   prev = current;
	   current = current->next;
	}
	//element not found
	if (current == NULL) {
	   return;
	}
	//remove element
	prev->next = current->next;
	free(current);
    }

