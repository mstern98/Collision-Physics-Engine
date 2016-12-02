
#include <stdio.h>
#include "../include/Object/Vector.h"

// currently this is test code

int main() 
{
	Vector* vec1 = vector_init(3.14, 4.20, 6.99);
	
	printf("vec1 x: %f vec1 y: %fvec1 z: %f \n", vec1->x, vec1->y, vec1->z);
	
	return 0;
}
