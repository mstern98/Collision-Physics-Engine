
#include "Object.h"

Object* initObject( int nv, struct Vector* v[nv])
{
	Object* obj = malloc(sizeof(Object));
	
	obj.hash_code = hashCode();
	obj.nv = nv
	Object->position = calloc(nv, sizeof(Vector));
	
	for (int i = 0; i < nv; i++)
	{
		obj->position[i] = v[i]
	}
	return obj;
}

int hashCode(Object* obj)
{
	int tmp;
	for (int i = 0; i < strlen(obj->name); i++)
	{
		tmp = tmp + (atoi(obj->name[i]) * pow(128, strlen(obj->name) - i));
	}
	
	return tmp;
}

bool equals(Object* one, Object* two)
{
	return (strcmp(one->name, two->name) == 0)? 1 : 0;
}