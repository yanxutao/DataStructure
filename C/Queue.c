#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define MAXSIZE 10
#define ERROR -1

typedef struct {
    ElementType Data[MAXSIZE];
    int front;
    int rear;
} Queue;

Queue *CreateQueue()
{
    Queue *Q;
    Q = (Queue *)malloc(sizeof(Queue));
    Q->front = -1;
    Q->rear = -1;
    return Q;
}

int IsFullQ(Queue *Q)
{
    return ((Q->rear + 1) % MAXSIZE == Q->front);
}   

int IsEmptyQ(Queue *Q)
{
    return (Q->front == Q->rear);
}

void AddQ(Queue *Q, ElementType item)
{
    if (IsFullQ(Q)) {
        printf("The queue is full!");
        return;
    }
    Q->rear = (Q->rear + 1) % MAXSIZE;
    Q->Data[Q->rear] = item;
}

ElementType DeleteQ(Queue *Q)
{
    if (IsEmptyQ(Q)) {
        printf("The queue is empty!");
        return ERROR;
    } else {
        Q->front = (Q->front + 1) % MAXSIZE;
        return Q->Data[Q->front];
    }
}
