#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define ElementType int

typedef struct {
	ElementType Data[MAXSIZE];
	int Top;
} Stack;

Stack *CreateStack()
{
	Stack *S;
	S = (Stack *)malloc(sizeof(Stack));
	S->Top = -1;
	return S;
}

int IsFull(Stack *S)
{
	return (S->Top == MAXSIZE - 1);
}

int IsEmpty(Stack *S)
{
	return (S->Top == -1);
}

void Push(Stack *S, ElementType item)
{
	if (IsFull(S)) {
		printf("The stack is full!");
		return;
	} else {
		S->Data[++(S->Top)] = item;
		return;
	}
}

ElementType Pop(Stack *S)
{
	if (IsEmpty(S)) {
		printf("The stack is empty!");
		return -1;
	} else {
		return (S->Data[(S->Top)--]);
	}
}
