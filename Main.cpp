#define _CRT_SECURE_NO_WARNINGS
#include "Table.h"
#include "Tree.h"
#include "Node.h"
#include <stdlib.h>
#include <stdio.h>
#define SIZE 256
#define MSG 1000

int main()
{
	Table *table = inizialise();
	char file[] = "text.txt";
	setTable(table, file);
	Table * tableCount = clearTable(table);
	int sizeTableCount = sizeTable(table);	
	Node *node = 0;
	for (int i = 0; i < sizeTableCount; i++) 
	{ 
		Tree *tree = (Tree *)malloc(sizeof(Tree));
		tree->table = tableCount[i];
		
		tree->code[0] = '\0';
		tree->left = NULL;
		tree->countRoot = tableCount[i].count;
		tree->right = NULL;	
	add2List(&node, (tree));
	}	
	for (int i = 0; i < sizeTableCount-1; i++)
	{
		Tree *t = (Tree *)malloc(sizeof(Tree));
		int n1 = node->tree.countRoot;
		int n2 = node->pnext->tree.countRoot;
		t->countRoot = n1 + n2;
		t->table.count = NULL;
		t->table.letter = NULL;
		t->code[0] = '\0';
		Tree *tLeft = (Tree *)malloc(sizeof(Tree));
		*tLeft = node->tree;
		Tree *tRigth = (Tree *)malloc(sizeof(Tree));
		*tRigth = (node->pnext)->tree;
		t->left = tLeft;
		t->right = tRigth;
		add2List(&node, t);
		deleteFirst(node);
		deleteFirst(node);
	}
	makeCodes(&node->tree);	
	Tree *rootHoff = &node->tree;
	FILE *stream = fopen(file, "r");
	char msg[SIZE] = {'\0'};
	printf("Code File \n");
	for (int i = 0; i < SIZE; i++)
	{
		msg[i] = fgetc(stream);
		char lett = msg[i];
		inL(rootHoff, lett);
		
	}
	puts("\n");
	fclose(stream);
	

	
	


	
	


	
}