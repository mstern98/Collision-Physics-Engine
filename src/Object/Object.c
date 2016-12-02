#include "../../include/Object/Object.h"

Object* obj_init(int hash_code, int nv, struct Vector* v[nv])
{
	Object* obj = malloc(sizeof(Object));
	
	obj->hash_code = hashCode(obj);
	obj->nv = nv;
	obj->position = calloc(nv, sizeof(Vector));

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

int equals(Object* one, Object* two)
{
	return (strcmp(one->name, two->name) == 0)? 1 : 0;
}
