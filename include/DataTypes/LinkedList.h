#include "../../include/Object/Object.h"
#include <stdbool.h>

#ifndef LINKED_LIST
#define LINKED_LIST

/*! LinkedList. */
/*! A list of pointers. */
typedef struct LinkedList 
{
	Object* obj; /*!< The object stored in the node. */
	struct LinkedList* parent; /*!< The parent node. */
	struct LinkedList* next; /*!< The next node. */
} LinkedList;

/*! Adds new objects to a linked list.
* \param obj The object being added to the list.
* \param list The list obj is being added to. 
*/
int ll_add(Object* obj, LinkedList* list);

/*! Deletes object from a linkedlist
*	\param Object* obj: obj to delete
*	\param LinkedList* list: list to delete from
*	\return Object* obj: obj deleted
*/
Object* ll_delete(const Object* obj, LinkedList* list);

/*! Searches linkedlist for object
*	\param Object* obj: obj to search for
*	\param LinkedList* list: list to search
*	\return LinkedList* search: returns searched linkedlist with searched object as root node, else NULL
*/
LinkedList* ll_search(const Object* obj, LinkedList* list);

#endif
