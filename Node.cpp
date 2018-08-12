#define _CRT_SECURE_NO_WARNINGS
#include "Node.h"
#include<stdlib.h>
#include<stdio.h>


void add2List(Node **pphead, Tree *t)
{
	Node **pp = pphead, *pnew;
	
	while (*pp)
	{
		if (t->countRoot <= (*pp)->tree.countRoot)
			break;
		else
			pp = &((*pp)->pnext);
	}
	pnew = (Node*)malloc(sizeof(Node));
	pnew->tree = *t;
	pnew->pnext = *pp;
	*pp = pnew;
}

void deleteFirst(Node *pphead)
{
	*pphead = *pphead->pnext;
}

void printNode(Node *phead)
{
	Node *p = phead;
	while (p)
	{
		printf("Letter %c ->  %d, count Root %d ",
			p->tree.table.letter, p->tree.table.count, p->tree.countRoot);
		printf("\n");
		p = p->pnext;
	}
}
