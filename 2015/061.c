
#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define MAXSIZE 10

#define MaxVertexNum 10
#define EdgeType int

typedef struct {
    ElementType Data[MAXSIZE];
    int front;
    int rear;
} Queue;
  
typedef struct {
    int n, e;
    EdgeType Edges[MaxVertexNum][MaxVertexNum];
    int Visited[MaxVertexNum];
} MGraph;

Queue *Q;
MGraph *G;

void CreateQueue()
{
    Q = (Queue *)malloc(sizeof(Queue));
    Q->front = -1;
    Q->rear = -1;
}

int IsFullQ(Queue *PtrQ)
{
    return ((PtrQ->rear + 1) % MAXSIZE == PtrQ->front) ? 1 : 0;
}   

int IsEmptyQ(Queue *PtrQ)
{
    return (PtrQ->front == PtrQ->rear) ? 1 : 0;
}

void AddQ(Queue *PtrQ, ElementType item)
{
    PtrQ->rear = (PtrQ->rear + 1) % MAXSIZE;
    PtrQ->Data[PtrQ->rear] = item;
}

ElementType DeleteQ(Queue *PtrQ)
{
    PtrQ->front = (PtrQ->front + 1) % MAXSIZE;
    return PtrQ->Data[PtrQ->front];
}

void CreateMGraph()
{
    G = (MGraph *)malloc(sizeof(MGraph));
    int i, j, k, w;
    scanf("%d %d", &(G->n), &(G->e));
    for (i = 0; i < G->n; i++)
       for (j = 0; j < G->n; j++)  
           G->Edges[i][j] = 0;
    for (k = 0; k < G->e; k++) {
       scanf("%d %d", &i, &j);
       G->Edges[i][j] = 1; 
       G->Edges[j][i] = 1;
    }
    for (i = 0; i < G->n; i++) {
       G->Visited[i] = 0;
   } 

}

void DFS(int i)
{
    G->Visited[i] = 1;
    printf("%d ", i);
    int j;
    for (j = 0; j < G->n; j++) {
        if (!G->Visited[j] && G->Edges[i][j])
            DFS(j);
    }
}

void BFS(int i)
{
    G->Visited[i] = 1;
    printf("%d ", i);
    AddQ(Q, i);
    while (!IsEmptyQ(Q)) {
        int j = DeleteQ(Q);
        int k;
        for (k = 0; k < G->n; k++) {
            if (!G->Visited[k] && G->Edges[j][k]) {
                G->Visited[k] = 1;
                printf("%d ", k);
                AddQ(Q, k);
            }
        }
    }
}

void ListComponents()
{
    int i;
    for (i = 0; i < G->n; i++) {
        if (!G->Visited[i]) {
            printf("{ ");
            DFS(i);
            printf("}\n");
        }
    }

    for (i = 0; i < G->n; i++)
        G->Visited[i] = 0;

    for (i = 0; i < G->n; i++) {
        if (!G->Visited[i]) {
            printf("{ ");
            BFS(i);
            printf("}\n");
        }
    }
}

int main()
{
    CreateQueue();
    CreateMGraph();
    ListComponents();
    return 0;
}