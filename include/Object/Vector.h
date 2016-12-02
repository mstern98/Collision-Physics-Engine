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

Vector* rotate(const float angle, Vector* v);
Vector* rotateTo(const Vector* to, Vector* v);
float dotProduct(const Vector* c, Vector* v);
Vector* crossProduct(const Vector* c, const Vector* v);
Vector* translate(const Vector* t, Vector* v);
Vector* normVector(const Vector* v);
float norm(const Vector* v);

Matrix* rot_x(const float* alpha);
Matrix* rot_y(const float* beta);
Matrix* rot_z(const float* gamma);


#endif