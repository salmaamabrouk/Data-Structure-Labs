#include <stdio.h>
#include <stdlib.h>

void swap(int *first, int *last)
{
    int temp = *first;
    *first = *last;
    *last = temp;
}

void bubble_sort(int *data, int size)
{
    int counter, index;
    int sorted = 0;

    for(counter = 0; counter < size - 1 && !sorted; counter++)
    {
        sorted = 1;

        for(index = 0; index < size - 1 - counter; index++)
        {
            if(data[index] > data[index + 1])
            {
                swap(&data[index], &data[index + 1]);
                sorted = 0;
            }
        }
    }
}

int binary_search(int item, int *data, int size)
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

void selection_sort(int *data, int size)
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

        swap(&data[counter], &data[minIndex]);
    }
}

void insertion_sort(int *data, int size)
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

void Display(int *data, int size)
{
    int index;

    for(index = 0; index < size; index++)
    {
        printf("%d  ", data[index]);
    }
}

int main()
{
    int arr[] = {4, 3, 5, 6, 2, 1};

    selection_sort(arr, 6);

    Display(arr, 6);

    return 0;
}
