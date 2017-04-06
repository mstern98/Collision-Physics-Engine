#include "../../include/DataTypes/OctTree.h"

OctTree* oct_init(Hashmap* h)
{
	OctTree* tmp = malloc(sizeof(OctTree*));
	
	memcpy(tmp->data, h, sizeof(h));
	
	tmp->children = calloc(sizeof(OctTree*), 8);
	
	return tmp;
}

int oct_add(const Object* obj) 
{
	return 1;
}

Object* oct_delete(Object* obj) 
{
	return obj;
}

int oct_search(const Object* obj) 
{
	return 1;
}



