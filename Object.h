#include <stdlib.h>

// TODO: work on commenting
typedef struct Object 
{
	// the xyz coordinate for the center of an object
	int x;
	int y;
	int z;
	
	// store the position of the object as an array of vectors
	Vector* position;
	
} Object;

// for now this is just a rectangular unit vector
typedef struct Vector
{
	int i;
	int j; 
	int k;
} Vector;

Object* initObject(int x, int y, int z, int nv, int id);


