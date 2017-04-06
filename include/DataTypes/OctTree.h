#include <stdlib.h>
#include "../../include/Object/Object.h"
#include "../../include/DataTypes.h"

#ifndef OCT_TREE
#define OCT_TREE

/*! OctTree. */
/*! A tree for mapping out Objects */
typedef struct OctTree 
{
	Hashmap* data; /*!< A hashmap for the objects in the node. */
	
	OctTree[8] children; /*!< Child nodes. */
} OctTree;

OctTree* oct_init(Hashmap* h);
int oct_add(const Object* obj, OctTree* oct);
Object* oct_delete(Object* obj, OctTree* oct);
int oct_search(const Object* obj, OctTree* oct);

#endif


