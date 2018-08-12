#define _CRT_SECURE_NO_WARNINGS
#include "Table.h"
#include<stdlib.h>
#include<stdio.h>
#define SIZE 256
#define MSG 1000

Table * inizialise()
{
	Table *table = (Table*)calloc(SIZE, sizeof(Table));
	for (int i = 0; i < SIZE; i++)
	{
		table[i].letter = i;
		table[i].count = 0;
	}
	return table;
}

void setTable(Table *table, char *file)
{
	FILE *stream = fopen(file, "r");
	char msg[MSG];
	for (int i = 0; i < MSG; i++)
	{
		msg[i] = fgetc(stream);
	}
	for (int i = 0; i < MSG; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (table[j].letter == msg[i])
			{
				table[j].count++;
			}
		}
	}
	fclose(stream);
}

void print(Table *t)
{
	for (int i = 0; i < SIZE; i++)
	{
		printf(" %c , -> %d\n", t[i].letter, t[i].count);
	}
}

void printOnSize(Table *t, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf(" %c , -> %d\n", t[i].letter, t[i].count);
	}
}

int sizeTable(Table * t)
{
	int sizeTable = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (t[i].count != 0)
		{
			sizeTable++;
		}
	}
	return sizeTable;
}

Table * clearTable(Table *t)
{
	int sizeNewTable = sizeTable(t);
	//printf("new suize %d \n", sizeNewTable);
	Table * table = (Table*)calloc(sizeNewTable, sizeof(Table));
	int j = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (t[i].count != 0)
		{
			table[j].letter= t[i].letter;
			table[j].count = t[i].count;
			j++;
		}
	}
	return table;
}

void sort(Table *t, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (t[j].count > t[j + 1].count)
			{
				Table temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
		}
	}
}


