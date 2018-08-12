#define _CRT_SECURE_NO_WARNINGS
#ifndef TABLE_H
#define TABLE_H

typedef struct Table
{
	char letter;
	int count;
	char codeLetter[256];
}Table;

Table * inizialise();
Table * clearTable(Table *t);
void printOnSize(Table *t, int size);
int sizeTable(Table * t);
void sort(Table *t, int size);
#endif 