#include "../../include/DataTypes/LinkedList.h"

#ifndef HASHMAP
#define HASHMAP
#define HASH_SIZE 10

LinkedList* elements;
void init();
int hash_add(const Object* obj);
Object* hash_delete(const Object* obj);
LinkedList* hash_search(const Object* obj);
int hash(const Object* obj);

#endif
