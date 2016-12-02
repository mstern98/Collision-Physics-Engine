/*
 * =====================================================================================
 *
 *       Filename:  OctTree.h
 *
 *    Description:  OctTree header file
 *
 *        Version:  1.0
 *        Created:  11/28/2016 03:26:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef Oct_Tree
#define Oct_Tree

void init(const Object* obj);
bool add(const Object* obj);
Object* delete(const Object* obj);
bool search(const Object* obj);

typedef struct Node
{	
	Node* left;
	Node* right;
	typedef struct Quad 
	{
		Quad* one;
		Quad* two;
		Quad* three;
		Quad* four;
	} Quad;
} Node;

#endif


