#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct Node {
    ElementType Data;
    struct Node *Next;
} LinkStack;

LinkStack *CreateStack()
{
    LinkStack *S;
    S = (LinkStack *)malloc(sizeof(struct Node));
    S->Next = NULL;
    return S;
}

int IsEmpty(LinkStack *S)
{
    return (S->Next == NULL);
}

void Push(LinkStack *S, ElementType item)
{
    LinkStack *TmpCell;
    TmpCell = (LinkStack *)malloc(sizeof(struct Node));
    TmpCell->Data = item;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
}

ElementType Pop(LinkStack *S)
{
    LinkStack *FirstCell;
    ElementType TopElem;
    if (IsEmpty(S)) {
        printf("The stack is empty!");
        return -1;
    } else {
        FirstCell = S->Next;
        S->Next = FirstCell->Next;
        TopElem = FirstCell->Data;
        free(FirstCell);
        return TopElem;
    }
}
