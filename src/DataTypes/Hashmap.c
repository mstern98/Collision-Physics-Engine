#include "../../include/DataTypes/Hashmap.h"

Hashmap* hash_init()
{
	Hashmap* tmp = malloc(sizeof(Hashmap*));
	tmp->elements = calloc(sizeof(LinkedList*), HASH_SIZE);
	
	return tmp;
}

int hash_add(const Object* obj, Hashmap* h)
{
	int key = hash(obj);
	
	ll_add(obj, h->elements[key]);
	return 1;
}

Object* hash_delete(const Object* obj, Hashmap* h)
{
	int key = hash(obj);
	
	return ll_delete(obj, h->elements[key]);
}

LinkedList* hash_search(const Object* obj, Hashmap* h)
{
	int key = hash(obj);
	if (h->elements[key] == NULL)
		return NULL;
	return ll_search(obj, h->elements[key]);
}
int hash(const Object* obj)
{
	float kA = obj->hash_code * (sqrt(5) - 1)/2;
	float fract = kA - (int) kA;
	int hash = (int) (10 * fract);
	return hash;
}
