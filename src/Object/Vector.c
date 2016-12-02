#include "../../include/Object/Vector.h"

Vector* vector_init(float x, float y, float z)
{
	Vector* vec = malloc(sizeof(Vector*));
	
	vec->x = x;
	vec->y = y;
	vec->z = z;
	
	return vec;
}

Plane* plane_init(Vector* perpendicular, Vector* a, Vector* b)
{
	Plane* tmp = malloc(sizeof(Plane*));
	
	tmp->perpendicular = perpendicular;
	tmp->a = a;
	tmp->b = b;
	
	return tmp;
}

Euler* euler_init(float alpha, float beta, float gamma)
{
	Euler* tmp = malloc(sizeof(Euler*));

	tmp->alpha = alpha;
	tmp->beta = beta;
	tmp->gamma = gamma;
	
	return tmp;
}

Vector* vector_multiply(const float size, Vector* v) 
{
	v->x *= size;
	v->y *= size;
	v->z *= size;
	
	return v;
}

Vector* vm_multiply(const Matrix* m, Vector* v)
{
	Vector* temp = malloc(sizeof(Vector*));
	
	temp->x = m->col_1->x * v->x + m->col_1->y * v->y + 
	m->col_1-> z * v->z;
	
	temp->y = m->col_2->x * v->x + m->col_2->y * v->y + 
	m->col_2-> z * v->z;
	
	temp->z = m->col_3->x * v->x + m->col_3->y * v->y + 
	m->col_3->z * v->z;
	
	v = temp;
	free(temp);
	
	return v;
}

Vector* vector_rotate(const Euler* e, Vector* v)
{
	Matrix* x = mat_rot_x(e->alpha);
	Matrix* y = mat_rot_y(e->beta);
	Matrix* z = mat_rot_z(e->gamma);
	
	vm_multiply(x, v);
	vm_multiply(y, v);
	return vm_multiply(z, v);
}

Matrix* mat_rot_x(const float alpha)
{
	Matrix* m = malloc(sizeof(Matrix*));
	
	m->col_1->x = 1.0f;
	m->col_1->y = 0.0f;
	m->col_1->z = 0.0f;
	
	m->col_2->x = 0.0f;
	m->col_2->y = (float) cos((double) alpha);
	m->col_2->z = (float) sin((double) alpha);
	
	m->col_3->x = 0.0f;
	m->col_3->y = -1.0f * sin((double) alpha);
	m->col_3->z = (float) cos((double) alpha);

	return m;
}
	
	
Matrix* mat_rot_y(const float beta)
{
	Matrix* m = malloc(sizeof(Matrix*));
	
	m->col_1->x = (float) cos((double) beta);
	m->col_1->y = 0.0f;
	m->col_1->z = -1.0f * sin((double) beta);
	
	m->col_2->x = 0.0f;
	m->col_2->y = 1.0f;
	m->col_2->z = 0.0f;
	
	m->col_3->x = (float) sin((double) beta);
	m->col_3->y = 0.0f;
	m->col_3->z = (float) cos((double) beta);

	return m;
}
Matrix* mat_rot_z(const float gamma)
{
	Matrix* m = malloc(sizeof(Matrix*));
	
	m->col_1->x = (float) cos((double) gamma);
	m->col_1->y = (float) sin((double) gamma);
	m->col_1->z = 0.0f;
	
	m->col_2->x = -1.0f * sin((double) gamma);
	m->col_2->y = (float) cos((double) gamma);
	m->col_2->z = 0.0f;
	
	m->col_3->x = 0.0f;
	m->col_3->y = 0.0f;
	m->col_3->z = 1.0f;

	return m;
}

Vector* vector_rotateTo(const Vector* to, Vector* v)
{
	Euler* e = malloc(sizeof(Euler*));
	
	float norm_to = norm(to);
	float norm_v = norm(v);
	
	e->alpha = acos(to->x / norm_to) - acos(v->x / norm_v);
	e->beta = acos(to->y / norm_to) - acos(v->y / norm_v);
	e->gamma = acos(to->z / norm_to) - acos(v->z / norm_v);
	
	return vector_rotate(e, v);
}

float dotProduct(const Vector* c, Vector* v)
{
	return (c->x * v->x) + (c->y * v->y) + (c->z * v->z);
}

Vector* crossProduct(const Vector* c, const Vector* v)
{
	Vector* tmp = malloc(sizeof(Vector*));
	
	tmp->x = (c->y * v->z) - (c->z * v->y);
	tmp->y = (c->x * v->z) - (c->z * v->x);
	tmp->z = (c->x * v->y) - (c->y * v->x);
	
	return tmp;
}

Vector* vector_translate(const Vector* t, Vector* v)
{
	v->x = t->x + v->x;
	v->y = t->y + v->y;
	v->z = t->z + v->z;
	
	return v;
}

Vector* normVector(const Vector* v)
{
	Vector* tmp = malloc(sizeof(Vector*));
	
	tmp->x = -1/v->x;
	tmp->y = -1/v->y;
	tmp->z = -1/v->z;
	
	return tmp;
}

float norm(const Vector* v)
{
	return sqrt(pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2));
}	

Vector* vector_add(Vector* a, Vector* b)
{
	Vector* tmp = malloc(sizeof(Vector*));
	
	tmp->x = a->x + b->x;
	tmp->y = a->y + b->y;
	tmp->z = a->z + b->z;
	
	return tmp;
}
Vector* vector_subtract(Vector* a, Vector* b)
{
	Vector* tmp = malloc(sizeof(Vector*));
	
	tmp->x = a->x - b->x;
	tmp->y = a->y - b->y;
	tmp->z = a->z - b->z;
	
	return tmp;
}

float dist_to_plane(Plane* p, Vector* v)
{
	return dotProduct(vector_multiply(1.0f / norm(p->perpendicular), p->perpendicular), vector_subtract(p->a, v));
}


































