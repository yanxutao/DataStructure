#include <stdio.h>
#include <stdlib.h>

#define ElementType int
#define MaxData 10000

typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
    ElementType *Elements;
    int Size;
    int Capacity;
};

MaxHeap Create(int MaxSize)
{
    MaxHeap H = malloc(sizeof(struct HeapStruct));
    H->Elements = malloc((MaxSize + 1) * sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MaxData;

    return H;
}

void Insert(MaxHeap H, ElementType item)
{
    int i = ++H->Size;
    for (; H->Elements[i / 2] < item; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = item;
}

void Path(MaxHeap H, int i)
{
    for (; i > 1; i /= 2) {
        printf("%d ", (-1) * H->Elements[i]);
    }
    printf("%d\n", (-1) * H->Elements[i]);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    MaxHeap H = Create(1000);
    int i, d;
    for (i = 0; i < n; i++) {
        scanf("%d", &d);
        Insert(H, (-1) * d);
    }
    for (i = 0; i < m; i++) {
        scanf("%d", &d);
        Path(H, d);
    }
    return 0;
}