#include <math.h>
#include <stdlib.h>

#ifndef VECTOR
#define VECTOR

typedef struct Vector
{
	float x;
	float y; 
	float z;
} Vector;

typedef struct Matrix
{
	Vector* col_1;
	Vector* col_2;
	Vector* col_3;
} Matrix;

typedef struct Euler
{
	float alpha; // rotate around x
	float beta; // rotate around y
	float gamma; // rotate around z
} Euler;

typedef struct Plane
{
	Vector* perpendicular;
	Vector* a;
	Vector* b;
} Plane;

Vector* vector_init(float x, float y, float z);
Plane* plane_init(Vector* perpendicular, Vector* a, Vector* b);
Euler* euler_init(float alpha, float beta, float gamma);

Vector* vector_multiply(const float size, Vector* v);
Vector* vector_rotate(const Euler* e, Vector* v);
Vector* vector_rotateTo(const Vector* to, Vector* v);
float dotProduct(const Vector* c, Vector* v);
Vector* crossProduct(const Vector* c, const Vector* v);
Vector* vector_translate(const Vector* t, Vector* v);
Vector* normVector(const Vector* v);
Vector* vector_add(Vector* a, Vector* b);
Vector* vector_subtract(Vector* a, Vector* b);
float norm(const Vector* v);

Matrix* mat_rot_x(const float alpha);
Matrix* mat_rot_y(const float beta);
Matrix* mat_rot_z(const float gamma);

float dist_to_plane(Plane* p, Vector* v);


#endif
