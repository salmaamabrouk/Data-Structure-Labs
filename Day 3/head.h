#ifndef x
#define x
#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node
{
    int X;
    Node *Prev, *Next;
};

Node *head = NULL, *tail = NULL;

void Add(int data);

void Swap(Node *first, Node *second);

void BubbleSort(Node *data, int size);

void SelectionSort(int *data, int size);

void InsertionSort(int *data, int size);

int BinarySearch(int item, int *data, int size);

void Display(int size);

#endif
