#include "Hashmap.h"

bool add(const Object* obj)
{
	int key = hash(obj);
	
	add(obj, elements[key]);
	return true;
}

Object* delete(const Object* obj)
{
	int key = hash(obj);
	
	return delete(obj, elements[key]);
}

LinkedList* search(const Object* obj)
{
	int key = hash(obj);
	if (elements[key] == NULL)
		return NULL;
	return search(obj, elements[key]);
}
int hash(const Object* obj)
{
	float kA = obj.hash_code * (sqrt(5) - 1)/2;
	float fract = kA - (int) kA;
	int hash = (int) (10 * fract);
	return hash;
}