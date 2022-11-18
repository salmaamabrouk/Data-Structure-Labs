#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node Node;

struct Node
{
    int Data;
    Node *Prev, *Next;
};

Node *head = NULL, *tail = NULL;

void Add(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = newNode->Next = NULL;

    if(head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->Next = newNode;
        newNode->Prev = tail;
        tail = newNode;
    }
}

void Display()
{
    Node *current = head;

    while(current != NULL)
    {
        printf("%d   ", current->Data);
        current = current->Next;
    }
}

Node* GetNodeByData(int data)
{
    Node *current = head;

    while(current != NULL)
    {
        if(data == current->Data)
            return current;

        current = current->Next;
    }

    return NULL;
}

void Remove(int data)
{
    Node *node = GetNodeByData(data);

    if(node == NULL)
        return;

    if(node == head)
    {
        if(head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            head = head->Next;
            head->Prev = NULL;
        }
    }
    else if(node == tail)
    {
        tail = tail->Prev;
        tail->Next = NULL;
    }
    else
    {
        node->Prev->Next = node->Next;
        node->Next->Prev = node->Prev;
    }

    free(node);
}

void InsertAfter(int data, int afterData)
{
    Node *current = head;

    while(current != NULL)
    {
        if(afterData == current->Data)
        {
            if (NULL == current->Next)
            {
                Add(data);
            }
            else
            {
                Node *newNode = malloc(sizeof(Node));
                newNode->Prev = current;
                newNode->Data = data;
                newNode->Next = current->Next;
                current->Next->Prev=newNode;
                current->Next=newNode;
            }
            return;
        }

        current = current->Next;
    }

}

int GetCount()
{
    Node *current = head;
    int num;
    while(current != NULL)
    {
        num++;
        current = current->Next;
    }
    return num;
}

int GetDataByIndex(int index)
{
    Node *current = head;
    int i=0;
    while(current != NULL && i<index)
    {
        if (i==index-1)
        {
            return current->Data;
        }
        i++;
        current=current->Next;
    }
    return NULL;
}
#endif
