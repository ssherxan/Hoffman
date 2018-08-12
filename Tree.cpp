#define _CRT_SECURE_NO_WARNINGS
#include "Tree.h"
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>

void createTree( Node * node, Tree *t)
{
		//Tree *pnew = (Tree *)malloc(sizeof(Tree));
		int node1 = node->tree.countRoot;
		int node2 = node->pnext->tree.countRoot;
		//t->code[0] = "";
		t->table.letter = NULL;
		t->table.count = NULL;
		t->countRoot = node1 + node2;;
		t->left = &node->tree;
		t->right = &(node->pnext->tree);
		
		add2List(&node,t);
		deleteFirst(node);
		deleteFirst(node);	
}
void in(Tree *root)
{
	if (root)
	{
		in(root->left);
		printf("letter: %c Code %s", root->table.letter, root->code);
		printf("\n");
		in(root->right);
	}
}


void makeCodes(Tree *root)
{
	if (root->left)
	{
		strcpy(root->left->code, root->code);
		strcat(root->left->code, "0");
		makeCodes(root->left);
	}
	if (root->right)
	{
		strcpy(root->right->code, root->code);
		strcat(root->right->code, "1");
		makeCodes(root->right);
	}
}

void inL(Tree *root, char letter)
{
	if (root)
	{
		inL(root->left,letter);
		if (root->table.letter==letter)
		{
			printf("%s",  root->code);	
		}
		inL(root->right, letter);
	}
}

