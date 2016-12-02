#include "LinkedList.h"

#ifndef HASHMAP
#define HASHMAP
#define HASH_SIZE 10

LinkedList[HASH_SIZE] elements;
bool add(const Object* obj);
Object* delete(const Object* obj);
LinkedList* search(const Object* obj);
int hash(const Object* obj);

#endif