#include "../../include/DataTypes/LinkedList.h"

#ifndef HASHMAP
#define HASHMAP
#define HASH_SIZE 1024

/*! Hashmap. */

typedef struct Hashmap 
{
	LinkedList* elements; /*! List of all the elements */
	
} Hashmap;

//!Initializes Hashmap
Hashmap* hash_init();


/*! Adds element to hashmap
*	\param Object* obj: Object to add
*	\param Hashmap* h: Hashmap to add Object to
*	\return 1
*/
int hash_add(const Object* obj, Hashmap* h);

/*! Deletes element from hashmap 
*	\param Object* obj: Object to remove
*	\param Hashmap* h: Hashmap to remove Object from
*	\return obj deleted
*/
Object* hash_delete(const Object* obj, Hashmap* h);

/*! Searches hashmap for element
*	\param Object* obj: Object to search for
*	\param Hashmap* h: Hashmap to search in
*	\return LinkedList* search: A linkedlist with the searched obj being the root node
*/
LinkedList* hash_search(const Object* obj, Hashmap* h);

/*! Returns hash key of object
*	\param Object* obj: Object to get hashcode of
*	\return int hash: hash of object
*/
int hash(const Object* obj);

#endif
