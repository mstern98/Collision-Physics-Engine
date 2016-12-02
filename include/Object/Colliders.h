
#include "../../include/Object/Vector.h"
#include "../../include/Object/Object.h"


#ifndef COLLIDERS
#define COLLIDERS

typedef struct CapsuleCollider
{
	float radius_one;
	float radius_two;
	
	Vector* center;

} CapsuleCollider;

typedef struct BoxCollider
{
	float length;
	float width;
	float height;

	Vector* reference;

} BoxCollider;

typedef struct CylinderCollider
{
	float radius;
	float height;

	Vector* reference;

} CylinderCollider;

typedef struct MeshCollider
{
	
} MeshCollider;

typedef enum 
{
	Q00, Q11, Q12, Q13, Q14, Q21, Q22, Q23, Q24, Q31, Q32, Q33, Q34, Q41, Q42, Q43, Q44
} Quadrant;

CapsuleCollider* capsule_init(const float r1, const float r2, const Object* obj);
BoxCollider* box_init(const float l, const float w, const float h, const Object* obj);
CylinderCollider* cylinder_init(const float r, const float h, const Object* obj);
MeshCollider* mesh_init();

Quadrant* box_quad(BoxCollider* box, const Plane* p1, const Plane* p2);
Quadrant* cap_quad(CapsuleCollider* cap, const Plane* p1, const Plane* p2);
Quadrant* cylinder_quad(CylinderCollider* cyl, const Plane* p1, const Plane* p2);
Quadrant* mesh_quad(MeshCollider* mesh, const Plane* p1, const Plane* p2);

void box_set_ref(BoxCollider* box, const Object* obj);
void cap_set_center(CapsuleCollider* cap, const Object* obj);
void cylinder_set_ref(CylinderCollider* cyl, const Object* obj);
void mesh_set_ref(MeshCollider* mesh, const Object* obj);



#endif
