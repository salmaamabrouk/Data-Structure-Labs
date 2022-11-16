#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int main()
{
    Add(3);
    Add(5);
    Add(7);
    Add(9);
    Add(8);

    InsertAfter(17,13);
    InsertAfter(6,4);
    InsertAfter(10,20);

    printf("%d\n",tail->Data);

    int x = GetCount();
    printf ("%d\t", x);
    Display();
    int in;
    printf("\nPlease enter the index \n");
    scanf("%d", &in);
    int y = GetDataByIndex(in);
    printf ("\n%d\t",y);


    return 0;
}
