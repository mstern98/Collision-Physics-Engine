#include <math.h>

#ifndef VECTOR
#define VECTOR

typedef struct Vector
{
	float* x;
	float* y; 
	float* z;
} Vector;

typedef struct Matrix
{
	Vector* col_1;
	Vector* col_2;
	Vector* col_3;
} Matrix;

typedef struct Euler
{
	float* alpha; // rotate around x
	float* beta; // rotate around y
	float* gamma; // rotate around z
} Euler;

Vector* initVector(float x, float y, float z);

int scale(const float size, Vector* v);

int rotate(const float angle, Vector* v);

Matrix* rot_x(const float* alpha);
Matrix* rot_y(const float* beta);
Matrix* rot_z(const float* gamma);


#endif