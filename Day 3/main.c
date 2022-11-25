#include "head.h"

void Swap(Node *f, Node *s)
{
    printf("Swap %d, %d\n",f->X,s->X);

    int temp = f->X;
    f->X = s->X;
    s->X = temp;
}

void BubbleSort(Node *ptrdata, int size)
{
    int counter, index;
    int sorted = 0;

    if (head == NULL)
    {
        return;
    }

    for(counter = 0; counter < size - 1 && !sorted; counter++)
    {
        sorted = 1;

        for(index = 0; index < size - 1 - counter && NULL != ptrdata->Next; index++)
        {
            printf("round %d\n",index);
            if(ptrdata->X > ptrdata->Next->X)
            {
                Swap(ptrdata, ptrdata->Next);
                sorted = 0;
            }
            ptrdata = ptrdata->Next;
        }
    }
}

int BinarySearch(int item, int *data, int size)
{
    int minIndex = 0, maxIndex = size - 1, midIndex;

    while(minIndex <= maxIndex)
    {
        midIndex = (minIndex + maxIndex) / 2;

        if(item == data[midIndex])
            return midIndex;

        if(item > data[midIndex])
            minIndex = midIndex + 1;
        else
            maxIndex = midIndex - 1;
    }

    return -1;
}
void SelectionSort(int *data, int size)
{
    int counter;

    for(counter = 0; counter < size - 1; counter++)
    {
        int minIndex = counter, index;

        for(index = minIndex + 1; index < size; index++)
        {
            if(data[index] < data[minIndex])
                minIndex = index;
        }

        Swap(&data[counter], &data[minIndex]);
    }
}

void InsertionSort(int *data, int size)
{
    int counter, key, index;

    for(counter = 1; counter < size; counter++)
    {
        key = data[counter];
        index = counter - 1;

        while(index >= 0 && data[index] > key)
        {
            data[index + 1] = data[index];
            index--;
        }
        data[index+1] = key;
    }
}

void Display(int size)
{
    int i = 0;
    Node *current = head;

    while(current != NULL && size > i)
    {
        printf("%d   ", current->X);
        current = current->Next;
        i++;
    }
}


void Add(int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->X = data;
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
        tail->Next = NULL;
    }
}

int main()
{
    int length = 0;
    int i;
    int arr[] = {3, 5, 1, 6, 4, 2};
    for (length = 0; arr[length] != NULL; length++)
        {}
    for (i = 0; i < length; i++)
    {
        Add (arr[i]);
    }

    BubbleSort(head, 6);

    Display(6);

    return 0;
}
