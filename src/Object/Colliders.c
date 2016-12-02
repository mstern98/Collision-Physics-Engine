#include "../../include/Object/Colliders.h"

CapsuleCollider* capsule_init(const float r1, const float r2, const Object* obj)
{
	CapsuleCollider* tmp = malloc(sizeof(CapsuleCollider*));
	
	tmp->radius_one = r1;
	tmp->radius_two = r2;
	tmp->center = obj->center;
	
	return tmp;
}
	
BoxCollider* box_init(const float l, const float w, const float h, const Object* obj)
{
	BoxCollider* tmp = malloc(sizeof(BoxCollider*));
	
	tmp->length = l;
	tmp->width = w;
	tmp->height = h;

	tmp->reference = obj->reference;

	return tmp;
}

CylinderCollider* cylinder_init(const float r, const float h, const Object* obj)
{
	CylinderCollider* tmp = malloc(sizeof(CylinderCollider*));

	tmp->radius = r;
	tmp->height = h;
	
	tmp->reference = obj->reference;
}

MeshCollider* mesh_init()
{
	//TODO: IDK
}

Quadrant* box_quad(BoxCollider* box, const Plane* p1, const Plane* p2)
{
	Vector** points = calloc(sizeof(Vector*), 8);
	float dist_to_plane_one[8];
	float dist_to_plane_two[8];

	points[0] = box->reference;
	points[1] = vector_add(box->reference, vector_init(box->length, 0.0f, 0.0f));
	points[2] = vector_add(box->reference, vector_init(box->length, box->width, 0.0f));
	points[3] = vector_add(box->reference, vector_init(0.0f, box->width, 0.0f));
	points[4] = vector_add(box->reference, vector_init(0.0f, 0.0f, box->height));
	points[5] = vector_add(box->reference, vector_init(box->length, 0.0f, box->height));
	points[6] = vector_add(box->reference, vector_init(box->length, box->width, box->height));
	points[7] = vector_add(box->reference, vector_init(0.0f, box->width, box-height));

	// TODO: check if a point is zero, or if two points are positive and negative to choose quadrants
		
	
}
Quadrant* cap_quad(CapsuleCollider* cap, const Plane* p1, const Plane* p2)
{
}
Quadrant* cylinder_quad(CylinderCollider* cyl, const Plane* p1, const Plane* p2)
{
}
Quadrant* mesh_quad(MeshCollider* mesh, const Plane* p1, const Plane* p2)
{
	//TODO: IDK
}

void box_set_ref(BoxCollider* box, const Object* obj)
{
	box->reference = obj->reference;
}
void cap_set_center(CapsuleCollider* cap, const Object* ob)
{
	cap->center = obj->center;
}
void cylinder_set_ref(CylinderCollider* cyl, const Object* ob)
{
	cyl->reference = obj->reference;
}
void mesh_set_ref(MeshCollider* mesh, const Object* ob)
{
	//TODO: IDK
}
