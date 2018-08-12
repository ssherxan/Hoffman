#define _CRT_SECURE_NO_WARNINGS
#ifndef TREE_H
#define TREE_H
#include "Table.h"
#define SIZE 256

typedef struct Tree
{
	Table table;
	char code[SIZE];
	int countRoot;
	struct Tree *left;
	struct Tree *right;
}Tree;
void in(Tree *root);
void inL(Tree *root, char letter);
#endif 