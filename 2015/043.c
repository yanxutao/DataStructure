#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct AVLTreeNode *AVLTree;
struct AVLTreeNode {
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

int Max(int a, int b)
{
    return a > b ? a : b;
}

int GetHeight(AVLTree A)
{
    if (!A)
        return 0;
    else
        return A->Height;
}

AVLTree SingleLeftRotation(AVLTree A)
{
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Left), A->Height) + 1;

    return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
    AVLTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Right), A->Height) + 1;

    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
    A->Left = SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}

AVLTree AVL_Insertion(ElementType X, AVLTree T)
{
    if (!T) {
        T = (AVLTree)malloc(sizeof(struct AVLTreeNode));
        T->Data = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    } else if (X < T->Data) {
        T->Left = AVL_Insertion(X, T->Left);
        if (GetHeight(T->Left) - GetHeight(T->Right) == 2)
            if (X < T->Left->Data)
                T = SingleLeftRotation(T);
            else
                T = DoubleLeftRightRotation(T);
    } else if (X > T->Data) {
        T->Right = AVL_Insertion(X, T->Right);
        if (GetHeight(T->Left) - GetHeight(T->Right) == -2)
            if (X > T->Right->Data)
                T = SingleRightRotation(T);
            else
                T = DoubleRightLeftRotation(T);
    }

    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;

    return T;
}

int main()
{
    int n;
    scanf("%d", &n);
    int i, d;
    AVLTree T = NULL;
    for (i = 0; i < n; i++) {
        scanf("%d", &d);
        T = AVL_Insertion(d, T);
    }
    printf("%d", T->Data);
    return 0;
}