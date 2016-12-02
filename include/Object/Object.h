#include <stdlib.h>
#include <string.h>
#include "Vector.h"

// TODO: work on commenting
// id: the ID of the object


// nv: the number of vectors that make up the object
typedef struct Object 
{
	int hash_code;
	int nv;
	char* name;
	// store the position of the object as an array of vectors
	Vector* position;
	
} Object;

Object* initObject(int nv, int hash_code);

int hashCode(Object* obj);

bool equals(Object* one, Object* two);


