#include "LinkedList.h"

bool add(const Object* obj, LinkedList* list)
{
	if (list->obj == NULL || list == NULL) 
	{
		list = malloc(sizeof(LinkedList));
		list->obj = malloc(sizeof(Object*));
		list->obj = obj;
		return true;
	}
	
	if (list->next == NULL) 
	{
		list->next = malloc(sizeof(LinkedList));
		list->next->obj = malloc(sizeof(Object*));
		list->next->obj = obj;
		return true;
	}
	else 
		return add(obj, list->next);
}

Object* delete(const Object* obj, LinkedList* list)
{
	if (list->obj == NULL || list == NULL)
		return NULL;
	if (equals(list->obj, obj))
	{
		Object* temp = list->obj;
		free(list->obj);
		list = list->next;
		return temp;
	}
	else
		return delete(obj, list->next);
}

LinkedList* search(const Object* obj, LinkedList* list)
{
	LinkedList* search = list;
	while(search->next != NULL) 
	{
		if (equals(search->obj, obj))
			return search;
	}
	return NULL;
}