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
	
	temp->x = m->row_1->x * v->x + m->row_1->y * v->y + 
	m->row_1-> z * v->z;
	
	temp->y = m->row_2->x * v->x + m->row_2->y * v->y + 
	m->row_2-> z * v->z;
	
	temp->z = m->row_3->x * v->x + m->row_3->y * v->y + 
	m->row_3->z * v->z;
	
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
	m->row_1 = malloc(sizeof(Vector*));
	m->row_2 =malloc(sizeof(Vector*));
	m->row_3 =malloc(sizeof(Vector*));
	
	m->row_1->x = 1.0f;
	m->row_1->y = 0.0f;
	m->row_1->z = 0.0f;
	
	m->row_2->x = 0.0f;
	m->row_2->y = (float) cos((double) alpha);
	m->row_2->z = (float) sin((double) alpha);
	
	m->row_3->x = 0.0f;
	m->row_3->y = -1.0f * sin((double) alpha);
	m->row_3->z = (float) cos((double) alpha);

	return m;
}
	
	
Matrix* mat_rot_y(const float beta)
{
	Matrix* m = malloc(sizeof(Matrix*));
	m->row_1 = malloc(sizeof(Vector*));
	m->row_2 =malloc(sizeof(Vector*));
	m->row_3 =malloc(sizeof(Vector*));
	
	m->row_1->x = (float) cos((double) beta);
	m->row_1->y = 0.0f;
	m->row_1->z = -1.0f * sin((double) beta);
	
	m->row_2->x = 0.0f;
	m->row_2->y = 1.0f;
	m->row_2->z = 0.0f;
	
	m->row_3->x = (float) sin((double) beta);
	m->row_3->y = 0.0f;
	m->row_3->z = (float) cos((double) beta);

	return m;
}
Matrix* mat_rot_z(const float gamma)
{
	Matrix* m = malloc(sizeof(Matrix*));
	m->row_1 = malloc(sizeof(Vector*));
	m->row_2 =malloc(sizeof(Vector*));
	m->row_3 =malloc(sizeof(Vector*));
	
	m->row_1->x = (float) cos((double) gamma);
	m->row_1->y = (float) sin((double) gamma);
	m->row_1->z = 0.0f;
	
	m->row_2->x = -1.0f * sin((double) gamma);
	m->row_2->y = (float) cos((double) gamma);
	m->row_2->z = 0.0f;
	
	m->row_3->x = 0.0f;
	m->row_3->y = 0.0f;
	m->row_3->z = 1.0f;

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

float dotProduct(const Vector* c, const  Vector* v)
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

Vector* vector_add(const Vector* a, const Vector* b)
{
	Vector* tmp = malloc(sizeof(Vector*));
	
	tmp->x = a->x + b->x;
	tmp->y = a->y + b->y;
	tmp->z = a->z + b->z;
	
	return tmp;
}
Vector* vector_subtract(const Vector* a, const Vector* b)
{
	Vector* tmp = malloc(sizeof(Vector*));
	
	tmp->x = a->x - b->x;
	tmp->y = a->y - b->y;
	tmp->z = a->z - b->z;
	
	return tmp;
}

Vector* vector_projection(const Vector* a, const Vector* u)
{
	Vector tmp = *u;
	return vector_multiply(dotProduct(a, u)/pow(norm(u), 2), &tmp);
}

float dist_to_plane(Plane* p, Vector* v)
{
	return dotProduct(vector_multiply(1.0f / norm(p->perpendicular), p->perpendicular), vector_subtract(p->a, v));
}

float determinant( const Matrix* m) 
{
	return (m->row_1->x * ((m->row_2->y * m->row_3->z) - (m->row_3->y * m->row_2->z))) -
	(m->row_2->x *((m->row_1->y * m->row_3->z) -  (m->row_3->y * m->row_1->x))) +
	(m->row_1->z * ((m->row_1->y * m->row_2->z) - (m->row_2->y * m->row_1->x)));
}
	
Matrix* transpose(const Matrix* m)
{
	Matrix* tmp = malloc(sizeof(Matrix*));
	tmp->row_1 = vector_init(m->row_1->x, m->row_2->x, m->row_3->x);
	tmp->row_2 = vector_init(m->row_1->y, m->row_2->y, m->row_3->y);
	tmp->row_3 = vector_init(m->row_1->z, m->row_2->z, m->row_3->z);
	
	return tmp;
}

Matrix* cofactor(const Matrix* m)
{
	Matrix* tmp = malloc(sizeof(Matrix*));
	
	tmp->row_1 = vector_init(((m->row_2->y * m->row_3->z) - (m->row_3->y * m->row_2->z)), -((m->row_1->y * m->row_3->z) - (m->row_3->y * m->row_1->x)), ((m->row_2->x  * m->row_3->y) - (m->row_2->y * m->row_1->x)));
	tmp->row_2 = vector_init( ( -(m->row_1->y * m->row_3->z) - (m->row_3->y * m->row_1->z)), ((m->row_1->x * m->row_3->z) - (m->row_1->z * m->row_3->x)), -((m->row_1->x * m->row_2->y) - (m->row_1->y * m->row_2->x)));
	tmp->row_3 = vector_init(((m->row_1->y * m->row_2->z) - (m->row_1->z * m->row_2->x)), -((m->row_1->x * m->row_2->z) - (m->row_1->z * m->row_2->x)), ((m->row_1->x * m->row_2->y) - (m->row_1->y * m->row_2->x)));
	
	return tmp;
}
	
Matrix* inverse(Matrix* m)
{
	float det = determinant(m);
	if (m == 0)
		return NULL;

	return matrix_scalar_muliply(1/det , transpose(cofactor(m)));
}

Matrix* matrix_scalar_muliply(const float f, Matrix* m)
{
	m->row_1->x = m->row_1->x * f;
	m->row_1->y= m->row_1->y * f;
	m->row_1->z = m->row_1->z * f;
	
	m->row_2->x = m->row_2->x * f;
	m->row_2->y= m->row_2->y * f;
	m->row_2->z = m->row_2->z * f;
	
	m->row_3->x = m->row_3->x * f;
	m->row_3->y= m->row_3->y * f;
	m->row_3->z = m->row_3->z * f;
	
	return m;
}
	
	
Matrix* matrix_multiply(const Matrix* c, Matrix* m)
{
	Matrix* tmp = malloc(sizeof(Matrix*));
	tmp->row_1 = malloc(sizeof(Vector*));
	tmp->row_2  = malloc(sizeof(Vector*));
	tmp->row_3 = malloc(sizeof(Vector*));
	
	
	tmp->row_1->x = c->row_1->x * m->row_1->x + c->row_1->y * m->row_2->x  + c->row_1->z * m->row_3->x;
	tmp->row_1->y = c->row_1->x * m->row_1->y + c->row_1->y * m->row_2->y  + c->row_1->z * m->row_3->y;
	tmp->row_1->z = c->row_1->x * m->row_1->z + c->row_1->y * m->row_2->z  + c->row_1->z * m->row_3->z;
	
	tmp->row_2->x = c->row_2->x * m->row_1->x + c->row_2->y * m->row_2->x  + c->row_2->z * m->row_3->x;
	tmp->row_2->y = c->row_2->x * m->row_1->y + c->row_2->y * m->row_2->y  + c->row_2->z * m->row_3->y;
	tmp->row_2->x = c->row_2->x * m->row_1->z + c->row_2->y * m->row_2->z  + c->row_2->z * m->row_3->z;

	tmp->row_3->x = c->row_3->x * m->row_1->x + c->row_3->y * m->row_2->x  + c->row_3->z * m->row_3->x;
	tmp->row_3->y = c->row_3->x * m->row_1->y + c->row_3->y * m->row_2->y  + c->row_3->z * m->row_3->y;
	tmp->row_3->x = c->row_3->x * m->row_1->z + c->row_3->y * m->row_2->z  + c->row_3->z * m->row_3->z;
	
	m = tmp;
	
	free(tmp);
	
	return m;
}

Vector* line_intersection(Line* a, Line* b)
{
	
}

Vector* lp_intersection(Line* l, Plane* p)
{
	
}

Vector* plane_intersection(Plane* a, Plane* b)
{
	
}

Vector* pv_intersection(const Line* l,  const Vector* v)
{
	Vector* x = vector_add(v, vector_multiply(-1, l->initial));
	if (x->x/l->slope->x == x->y/l->slope->y &&  x->y/l->slope->y  == x->z/l->slope->z)
		return vector_add(vector_multiply(x->x/l->slope->x, l->slope), l->initial);
	return NULL;
}

































