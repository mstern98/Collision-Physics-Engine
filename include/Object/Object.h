#include <stdlib.h>
#include <string.h>
#include "../../include/Object/Vector.h"

#ifndef OBJECT
#define OBJECT

// TODO: work on commenting
// id: the ID of the object


// nv: the number of vectors that make up the object
typedef struct Object 
{
	int hash_code;
	int nv;
	const char* name;
	// store the position of the object as an array of vectors
	Vector* position;
	
} Object;

Object* obj_init(int hash_code, int nv, struct Vector* v[nv]);

int hashCode(Object* obj);

int equals(Object* one, Object* two);

#endif


