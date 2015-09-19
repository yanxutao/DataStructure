#include <stdio.h>
#include <stdlib.h>

#define ElementType int

typedef struct {
    ElementType Data;
    int Parent;
} SetType;

int Find(SetType S[], ElementType X)
{
    int i;
    for (i = 0; S[i].Data != X; i++);
    for (; S[i].Parent >= 0; i = S[i].Parent);
    return i;
}

void Check(SetType S[], ElementType n1, ElementType n2)
{
    if (Find(S, n1) == Find(S, n2))
        printf("yes\n");
    else
        printf("no\n");
}

void Union(SetType S[], ElementType X1, ElementType X2)
{
    int Root1, Root2;
    Root1 = Find(S, X1);
    Root2 = Find(S, X2);
    if (Root1 != Root2) {
        if (S[Root1].Parent < S[Root2].Parent) {
            S[Root1].Parent += S[Root2].Parent;
            S[Root2].Parent = Root1;
        } else {
            S[Root2].Parent += S[Root1].Parent;
            S[Root1].Parent = Root2;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    SetType *S = (SetType *)malloc(n * sizeof(SetType));
    int i;
    for (i = 0; i < n; i++) {
        S[i].Data = i + 1;
        S[i].Parent = -1;
    }

    char c;
    int n1, n2;
    while(1) {
        scanf("%c", &c);
        if (c == 'S')
            break;
        else {
            scanf("%d %d", &n1, &n2);
            if (c == 'C')
                Check(S, n1, n2);
            else if (c == 'I')
                Union(S, n1, n2);
        }
    }

    int k = 0;
    for (i = 0; i < n; i++) {
        if (S[i].Parent < 0)
            k++;
    }
    if (k == 1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n", k);

    return 0;
}