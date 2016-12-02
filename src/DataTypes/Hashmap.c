#include "../../include/DataTypes/Hashmap.h"

void init()
{
	elements = calloc(sizeof(LinkedList*), HASH_SIZE);
}

int hash_add(const Object* obj)
{
	int key = hash(obj);
	
	ll_add(obj, &elements[key]);
	return 1;
}

Object* hash_delete(const Object* obj)
{
	int key = hash(obj);
	
	return ll_delete(obj, &elements[key]);
}

LinkedList* hash_search(const Object* obj)
{
	int key = hash(obj);
	if (&elements[key] == NULL)
		return NULL;
	return ll_search(obj, &elements[key]);
}
int hash(const Object* obj)
{
	float kA = obj->hash_code * (sqrt(5) - 1)/2;
	float fract = kA - (int) kA;
	int hash = (int) (10 * fract);
	return hash;
}
