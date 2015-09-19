#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k;
    scanf("%d", &k);
    int i;
    int *d = (int *)malloc(k * sizeof(int));
    for (i = 0; i < k; i++)
        scanf("%d", d + i);

    int max = d[0];
    int begin;
    int end;
    begin = end = d[0];

    int tmpmax = 0;
    int tmpbegin;
    int tmpend;
    tmpbegin = tmpend = d[0];

    for (i = 0; i < k; i++) {
        tmpmax += d[i];
        if (tmpmax < 0) {
            tmpmax = 0;
            tmpbegin = tmpend = d[i + 1];
        } else if (tmpmax <= max) {
            tmpend = d[i];
        } else {
            max = tmpmax;
            begin = tmpbegin;
            end = d[i];
        } 
    }
    
    if (max < 0)
        printf("0 %d %d", d[0], d[k - 1]);
    else
        printf("%d %d %d", max, begin, end);

    return 0;
}