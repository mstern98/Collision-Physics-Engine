#include "../../include/DataTypes/LinkedList.h"

int ll_add(Object* obj, LinkedList* list)
{
	if (list->obj == NULL) 
	{
		list = malloc(sizeof(LinkedList));
		list->obj = malloc(sizeof(Object*));
		list->obj = obj;
		return 1;
	}
	
	if (list->next == NULL) 
	{
		list->next = malloc(sizeof(LinkedList));
		list->next->obj = malloc(sizeof(Object*));
		list->next->obj = obj;
		return 1;
	}
	else 
		return ll_add(obj, list->next);
}

Object* ll_delete(const Object* obj, LinkedList* list)
{
	if (list->obj == NULL)
		return NULL;
	if (equals(list->obj, obj))
	{
		Object* temp = list->obj;
		free(list->obj);
		list = list->next;
		return temp;
	}
	else
		return ll_delete(obj, list->next);
}

LinkedList* ll_search(const Object* obj, LinkedList* list)
{
	LinkedList* search = list;
	while(search->next != NULL) 
	{
		if (equals(search->obj, obj))
			return search;
	}
	return NULL;
}
