
#include "Object.h"

Object* initObject(int x, int y, int z, int nv, int id)
{
	Object* obj = malloc(sizeof(Object));
	
	Object->x = x;
	Object->y = y;
	Object->z = z;
	
	Object->position = calloc(nv, sizeof(Vector));
	
	return obj;
}