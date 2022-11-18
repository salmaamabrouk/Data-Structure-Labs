#ifndef QUEUE_H
#define QUEUE_H
#define MaxQSize 5

typedef struct Queue
{
    int arr[MaxQSize];
    int front, rear;

}Queue;

void EnQueue(Queue *q, int data)
{
    if(q->rear == MaxQSize - 1)
        return;

    if(q->front == -1)
        q->front++;

    q->rear++;
    q->arr[q->rear] = data;
}

int DeQueue(Queue *q, int *data)
{
    q->front++;

    if(q->front == -1)
    {
        return 0;
    }
    else
    {
        *data = q->arr[q->front];
        q->front++;

        return 1;
    }
}

#endif
