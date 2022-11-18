#ifndef STACK_H
#define STACK_H
#define MaxSize 5

typedef struct Stack
{
    int arr[MaxSize];
    int top;
}Stack;

int Push(Stack *stk, int data)
{
    if(stk->top == MaxSize - 1)
        return 0;

    stk->top++;
    stk->arr[stk->top] = data;
    return 1;
}

int Pop(Stack *stk, int *data)
{
    if(stk->top == -1)
    {
        return 0;
    }

    *data = stk->arr[stk->top];
    stk->top--;

    return 1;
}

#endif
