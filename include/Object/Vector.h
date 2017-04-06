#include <math.h>
#include <stdlib.h>
#include <limits.h>

#ifndef VECTOR
#define VECTOR

#define EPSILON 0.0000000001

/*! Vector */
/* A position in space */
typedef struct Vector
{
	float x; /*!< The x coordinate */
	float y; /*!< The y coordinate */
	float z; /*!< The z coordinate */
} Vector;

/*! Matrix */
/*! A linear operation */
typedef struct Matrix
{
	Vector* row_1; /*!< The 1st row */
	Vector* row_2; /*!< The 2nd row */
	Vector* row_3; /*!< The 3rd row */
} Matrix;

/*! Euler */
/*! Angles */
typedef struct Euler
{
	float alpha; /*!< rotate around x */
	float beta; /*!< rotate around y */
	float gamma; /*!< rotate around z */
} Euler;

/*! Plane */

typedef struct Plane
{
	Vector* perpendicular;
	Vector* a;
	Vector* b;
} Plane;

/*! Line */
typedef struct Line
{
	Vector* slope;
	Vector* initial;
} Line;

Vector* vector_init(float x, float y, float z);
Plane* plane_init(Vector* perpendicular, Vector* a, Vector* b);
Euler* euler_init(float alpha, float beta, float gamma);
Line* line_init(Vector* s, Vector* i);

Vector* vector_multiply(const float size, Vector* v);
Vector* vector_rotate(const Euler* e, Vector* v);
Vector* vector_rotateTo(const Vector* to, Vector* v);
float dotProduct(const Vector* c, const  Vector* v);
Vector* vector_crossProduct(const Vector* c, const Vector* v);
Vector* vector_translate(const Vector* t, Vector* v);
Vector* normVector(const Vector* v);
Vector* vector_add(const Vector* a, const Vector* b);
Vector* vector_subtract(const Vector* a, const Vector* b);
Vector* vector_projection(const Vector* a, const Vector* u);
float determinant( const Matrix* m);
float norm(const Vector* v);
int vector_equals(Vector* a, Vector* b);
Vector* invertNormal(Vector* a);

Matrix* mat_rot_x(const float alpha);
Matrix* mat_rot_y(const float beta);
Matrix* mat_rot_z(const float gamma);
Matrix* transpose(const Matrix* m);
Matrix* cofactor(const Matrix* m);
Matrix* matrix_scalar_muliply(const float f, Matrix* m);
Matrix* matrix_multiply(const Matrix* c, Matrix* m);

float dist_to_plane(Plane* p, Vector* v);

int line_intersection(Line* a, Line* b);
Vector* lp_intersection(Line* l, Plane* p);
Line* plane_intersection(Plane* a, Plane* b);
Vector* pv_intersection(const Line* l,  const Vector* v);


#endif
