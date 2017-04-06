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
    
    Vector* center;
    Vector* reference;
	
} Object;

/*!	Initializes object
*	\param char** name: name of object
*	\param int nv: number of vectors 
*	\param struct Vector* v[nv]: array of Vector
*	\return Object* obj: returns initialized object
*/
Object* obj_init(char** name, int nv, struct Vector* v[nv]);

/*! Gets hashcode of object
*	\param Object* obj: obj to get hashcode of
*	\return int hashCode: hash code
*/
int hashCode(Object* obj);

/*!	Compares to objects
*	\param Object* one
*	\param Object* two
*	\return int equals: if equals, returns 1; else 0
*/
int equals(Object* one, Object* two);

#endif


