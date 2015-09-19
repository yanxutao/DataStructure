#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define ERROR -1

typedef struct Node {
    ElementType Data;
    struct Node *Next;
} QNode;
typedef struct {
    QNode *front;
    QNode *rear;
} LinkQueue;

LinkQueue *CreateQueue()
{
    LinkQueue *Q;
    Q = (LinkQueue *)malloc(sizeof(LinkQueue));
    Q->front = NULL;
    Q->rear = NULL;
    return Q;
}

int IsEmptyQ(LinkQueue *Q)
{
    return (Q->front == NULL || Q->rear == NULL);
}

void AddQ(LinkQueue *Q, ElementType item)
{
    QNode *RearCell;
    RearCell = (QNode *)malloc(sizeof(QNode));
    RearCell->Data = item;
    RearCell->Next = NULL;
    if (IsEmptyQ(Q)) {
        Q->front = Q->rear = RearCell;
    } else {
        Q->rear->Next = RearCell;
        Q->rear = RearCell;
    }
}

ElementType DeleteQ(LinkQueue *Q)
{
    QNode *FrontCell;
    ElementType FrontElem;
    if (IsEmptyQ(Q)) {
        printf("The queue is empty!");
        return ERROR;
    }
    FrontCell = Q->front;
    if (Q->front == Q->rear) {
        Q->front = Q->rear = NULL;
    } else {
        Q->front = Q->front->Next;
    }
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}
