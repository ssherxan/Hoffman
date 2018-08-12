#define _CRT_SECURE_NO_WARNINGS
#ifndef NODE_H
#define NODE_H
#include "Tree.h"
typedef struct Node
{
	Tree tree;
	struct Node *pnext;
}Node;

void add2List(Node ** pphead, Tree * t);
void deleteFirst(Node * pphead);
void printNode(Node *phead);
//int sumElem(Node *node);
//int maxElem(Node *node);
#endif 
