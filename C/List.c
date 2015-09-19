#include <stdio.h>
#include <stdlib.h>

#define ElementType 
#define MAXSIZE 

typedef struct {
	ElementType Data[MAXSIZE];
	int Last;
} List;
List L, *PtrL;

List *MakeEmpty()
{
	List *PtrL;
	PtrL = (List *)malloc(sizeof(List));
	PtrL->Last = -1;
	return PtrL;
}

ElementType FindKth(int K, List *PtrL)
{
	if (K < 1 || K > PtrL->Last + 1) {
		printf("Invalid position!");
	} else {
		return PtrL->Data[K - 1];
	}
}

int Find(ElementType X, List *PtrL)
{
	int i = 0;
	while (i <= PtrL->Last && PtrL->Data[i] != X)
		i++;
	if (i > PtrL->Last) return -1;
	else return i; 
}

void Insert(ElementType X, int i, List *PtrL)
{
	int j;
	if (PtrL->Last == MAXSIZE - 1) {
		printf("The List if full!");
		return;
	}
	if (i < 1 || i > PtrL->Last + 2) {
		printf("Invalid insert position: %d", i);
		return;
	}
	for (j = PtrL->Last; j >= i - 1; j--) {
		PtrL->Data[j + 1] = PtrL->Data[j];
	}
	PtrL->Data[i - 1] = X;
	PtrL->Last++;
	return;
}

void Delete(int i, List *PtrL)
{
	int j;
	if (i < 1 || i > PtrL->Last + 1) {
		printf("The %dth element does not exist!", i);
		return;
	}
	for (j = i; j <= PtrL->Last; j++) {
		PtrL->Data[j - 1] = PtrL->[j];
	}
	PtrL->Last--;
	return;
}
	
int Length(List *PtrL)
{
	return PtrL->Last + 1;
}