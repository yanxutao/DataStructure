#include <stdio.h>
#include <stdlib.h>

void print(int i)
{
    if (i >= 1 && i <= 13)
        printf("S%d", i);
    else if (i >= 14 && i <= 26)
        printf("H%d", i - 13);
    else if (i >= 27 && i <= 39)
        printf("C%d", i - 26);
    else if (i >= 40 && i <= 52)
        printf("D%d", i - 39);
    else if (i >= 53 && i <= 54)
        printf("J%d", i - 52); 
}

int main()
{
    int k;
    int shu[54];
    scanf("%d", &k);
    int i;
    for (i = 0; i < 54; i++)
        scanf("%d", shu + i);

    int s[54];
    for (i = 0; i < 54; i++)
        s[i] = i + 1;

    int d[54];

    int j;
    int *st, *dt, *t;
    st = s;
    dt = d;
    for (j = 0; j < k; j++) {
        for (i = 0; i < 54; i++) {
            dt[shu[i] - 1] = st[i];
        }
        t = dt;
        dt = st;
        st = t;
    }

    for (i = 0; i < 53; i++) {
        print(st[i]);
        printf(" ");
    }
    print(st[53]);

    return 0;
}