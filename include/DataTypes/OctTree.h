#include <stdlib.h>
#include "../../include/Object/Object.h"

#ifndef OCT_TREE
#define OCT_TREE


void oct_init(const Object* obj);
int oct_add(const Object* obj);
Object* oct_delete(Object* obj);
int oct_search(const Object* obj);

#endif


