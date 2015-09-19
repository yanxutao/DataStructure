#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 30
#define ERROR -1
#define ElementType int

typedef struct tnode *BinTree;
typedef struct tnode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
} TreeNode;

BinTree TreePtr;

void PreInToPost(ElementType pre[], int b1, int e1, ElementType in[], int b2, int e2)
{

}

struct {
	ElementType Data[MAXSIZE];
	int Top;
} Stack;

int IsFull()
{
	return Stack.Top == MAXSIZE - 1 ? 1 : 0;
}

int IsEmpty()
{
	return Stack.Top == -1 ? 1 : 0;
}

void Push(ElementType item)
{
	if (IsFull()) {
		printf("The stack is full!");
		return;
	} else {
		Stack.Data[++(Stack.Top)] = item;
		return;
	}
}

ElementType Pop()
{
	if (IsEmpty()) {
		printf("The stack is empty!");
		return ERROR;
	} else {
		return (Stack.Data[(Stack.Top)--]);
	}
}

int main()
{
	TreePtr = (TreePtr)malloc(sizeof(TreeNode));
	Stack.Top = -1;
	int pre[30], in[30], post[30];

	char op[5];
	int index;

	int n;
	scanf("%d", &n);
	int i, j = 0, k = 0;
	for (i = 0; i < 2 * n; i++) {
		scanf("%s", op);
		if (strcmp(op, "Push") == 0) {
			scanf("%d", &index);
			pre[j++] = index;
			Push(index);
		} else {
			in[k++] = Pop();
		}
	}

	root = pre[0];
	for (i = 0; root != in[i]; i++);
	0--i - 1
	i + 1--n
	

	for (i = 0; i < n; i++) {
		printf("%d ", pre[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d ", in[i]);
	}

	return 0;
}