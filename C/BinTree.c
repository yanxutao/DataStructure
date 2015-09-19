#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

void PreOrderTraversal(BinTree BT)
{
	if (BT) {
		printf("%d", BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}
}

void InOrderTraversal(BinTree BT)
{
	if (BT) {
		InOrderTraversal(BT->Left);
		printf("%d", BT->Data);
		InOrderTraversal(BT->Right);
	}
}

void PostOrderTraversal(BinTree BT)
{
	if (BT) {
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Right);
		printf("%d", BT->Data);
	}
}

//堆栈
void InOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);
	while (T || IsEmpty(S)) {
		while(T) {
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);
			printf("%d", T->Data);
			T = T->Right;
		}
	}
}

void PreOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);
	while (T || IsEmpty(S)) {
		while(T) {
			printf("%d", T->Data);
			Push(S, T);
			T = T->Left;
		}
		if (!IsEmpty(S)) {
			T = Pop(S);
			T = T->Right;
		}
	}
}

void LevelOrderTraversal(BinTree BT)
{
	Queue Q;
	BinTree T;
	if (!BT)
		return;
	Q = CreatQueue(MaxSize);
	AddQ(Q, BT);
	while (!IsEmptyQ(Q)) {
		T = DeleteQ(Q);
		printf("%d", T->Data);
		if (T->Left)
			AddQ(Q, T->Left);
		if (T->Right)
			AddQ(Q, T->Right);
	}
}

void PreOrderPrintLeaves(BinTree BT)
{
	if (BT) {
		if (!BT->Left && !BT->Right)
			printf("%d", BT->Data);
		PreOrderPrintLeaves(BT->Left);
		PreOrderPrintLeaves(BT->Right);
	}
}

int PostOrderGetHeight(BinTree BT)
{
	int HL, HR, MaxH;
	if (BT) {
		HL = PostOrderGetHeight(BT->Left);
		HR = PostOrderGetHeight(BT->Right);
		MaxH = (HL > HR) ? HL : HR;
		return (MaxH + 1);
	} else
		return 0;
}

Position Find(ElementType X, BinTree BST)
{
	if (!BST)
		return NULL;
	if (X > BST->Data)
		return Find(X, BST->Right);
	else if (X < BST->Data)
		return Find(X, BST->Left);
	else
		return BST;
}

Position IterFind(ElementType X, BinTree BST)
{
	while (BST) {
		if (X > BST->Data)
			BST = BST->Right;
		else if (X < BST->Data)
			BST = BST->Left;
		else
			return BST;
	}
	return NULL;
}

Position FindMin(BinTree BST)
{
	if (!BST)
		return NULL;
	else if (!BST->Left)
		return BST;
	else
		return FindMin(BST->Left);
}

Position FindMax(BinTree BST)
{
	if (!BST)
		return NULL;
	else if (!BST->Right)
		return BST;
	else
		return FindMax(BST->Right);
}

Position FindMin(BinTree BST)
{
	if (BST)
		while (BST->Left)
			BST = BST->Left;
	return BST;
}

Position FindMax(BinTree BST)
{
	if (BST)
		while (BST->Right)
			BST = BST->Right;
	return BST;
}

BinTree Insert(ElementType X, BinTree BST)
{
	if (!BST) {
		BST = malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->Left = BST->Right = NULL;
	} else {
		if (X < BST->Data)
			BST->Left = Insert(X, BST->Left);
		else if (X > BST->Data)
			BST->Right = Insert(X, BST->Right);
	}
	return BST;
}

BinTree Delete(ElementType X, BinTree BST)
{
	Position Tmp;
	if (!BST)
		printf("The element was not found!");
	else if (X < BST->Data)
		BST->Left = Delete(X, BST->Left);
	else if (X > BST->Data)
		BST->Right = Delete(X, BST->Right);
	else {
		if (BST->Left && BST->Right) {
			Tmp = FindMin(BST->Right);
			BST->Data = Tmp->Data;
			BST->Right = Delete(BST->Data, BST->Right);
		} else {
			Tmp = BST;
			if (!BST->Left)
				BST = BST->Right;
			else if (!BST->Right)
				BST = BST->Left;
			free(Tmp);
		}
	}
	return BST;
}

Boolean IsEmpty(BinTree BT)

void Traversal(BinTree BT)

BinTree CreatBinTree()