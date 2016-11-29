#include "Object.h"
#include <stdbool.h>

#ifndef LINKED_LIST
#define LINKED_LIST

/*! LinkedList. */
/*! A list of pointers. */
typedef struct LinkedList 
{
	Object* obj; /*!< The object stored in the node. */
	Node* parent; /*!< The parent node. */
	Node* next; /*!< The next node. */
} LinkedList;

/*! add. */
/*! Adds new objects to a linked list.
* \param obj The object being added to the list.
* \param list The list obj is being added to. 
*/
bool add(const Object* obj, LinkedList* list);


Object* delete(const Object* obj, LinkedList* list);
LinkedList* search(const Object* obj, LinkedList* list);

#endif