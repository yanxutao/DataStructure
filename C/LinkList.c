#include <stdio.h>
#include <stdlib.h>

#define ElementType 

typedef struct Node {
    ElementType Data;
    struct Node *Next;
} List;
List L, *PtrL;

List *MakeEmpty()
{
    List *PtrL = NULL;
    return PtrL;
}

List *FindKth(int K, List *PtrL)
{
    List *p = PtrL;
    int i = 1;
    while (p != NULL && i < K) {
        p = p->Next;
        i++;
    }

    if (i == K) {
        return p;
    } else {
        return NULL;
    }
}

int Find(ElementType X, List *PtrL)
{
    List *p = PtrL;
    while (p != NULL && p->Data != X) {
        p = p->Next;
    }
    return p - PtrL;
}

List *Insert(ElementType X, int i, List *PtrL)
{
    List *p, *s;
    if (i == 1) {
        s = (List *)malloc(sizeof(List));
        s->Data = X;
        s->Next = PtrL;
        return s;
    }
    p = FindKth(i - 1, PtrL);
    if (p == NULL) {
        printf("Wrong parameter i: %d", i);
        return NULL;
    } else {
        s = (List *)malloc(sizeof(List));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}

List *Delete(int i, List *PtrL)
{
    List *p, *s;
    if (i == 1) {
        s = PtrL;
        if (PtrL != NULL) {
            PtrL = PtrL->Next;
        } else {
            return NULL;
        }
        free(s);
        return PtrL;
    }
    p = FindKth(i - 1, PtrL);
    if (p == NULL) {
        printf("The %dth node does not exist!", i - 1);
    } else if (p->Next == NULL) {
        printf("The %dth node does not exist!", i);
    } else {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return PtrL;
    }
}

int Length(List *PtrL)
{
    List *p = PtrL;
    int j = 0;
    while (p) {
        j++;
        p = p->Next;
    }
    return j;
}