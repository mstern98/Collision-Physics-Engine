#include "Vector.h"

Vector* initVector(float x, float y, float z)
{
	Vector* vec = malloc(sizeof(Vector))
	
	vec->x = x;
	vec->y = y;
	vec->z = z;
}


Vector* scale(float size, Vector* v) 
{
	v->x *= size;
	v->y *= size;
	v->z *= size;
	
	return v;
}

Vector* multiply(const Matrix* m, Vector* v)
{
	Vector* temp = malloc(sizeof(Vector*));
	
	temp->x = m->col_1->x * v->x + m->col_1->y * v->y + 
	m->col_1-> z * v->z;
	
	temp->y = m->col_2->x * v->x + m->col_2->y * v->y + 
	m->col_2-> z * v->z;
	
	temp->z = m->col_3->x * v->x + m->col_3->y * v->y + 
	m->col_3-> z * v->z;
	
	v = temp;
	free(temp);
	
	return v;
}

Vector* rotate(const Euler* e, Vector* v)
{
	Matrix* x = rot_x(e->alpha);
	Matrix* y = rot_y(e->beta);
	Matrix* z = rot_z(e->gamma);
	
	multiply(x, v);
	multiply(y, v);
	return multiply(z, v);
}

Matrix* rot_x(const float* alpha)
{
	Matrix* m = malloc(sizeof(Matrix*));
	
	m->col_1->x = 1;
	m->col_1->y = 0;
	m->col_1->z = 0;
	
	m->col_2->x = 0;
	m->col_2->y = cos(alpha);
	m->col_2->z = sin(alpha);
	
	m->col_3->x = 0;
	m->col_3->y = -1 * sin(alpha);
	m->col_3->z = cos(alpha);

	return m;
}
	
	
Matrix* rot_y(const float* beta)
{
	Matrix* m = malloc(sizeof(Matrix*));
	
	m->col_1->x = cos(beta);
	m->col_1->y = 0;
	m->col_1->z = -1 * sin(beta);
	
	m->col_2->x = 0;
	m->col_2->y = 1;
	m->col_2->z = 0;
	
	m->col_3->x = sin(beta);
	m->col_3->y = 0;
	m->col_3->z = cos(beta);

	return m;
}
Matrix* rot_z(const float* gamma)
{
	Matrix* m = malloc(sizeof(Matrix*));
	
	m->col_1->x = cos(gamma);
	m->col_1->y = sin(gamma);
	m->col_1->z = 0;
	
	m->col_2->x = -1 * sin(gamma);
	m->col_2->y = cos(gamma);
	m->col_2->z = 0;
	
	m->col_3->x = 0;
	m->col_3->y = 0;
	m->col_3->z = 1;

	return m;
}

















