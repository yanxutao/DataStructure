#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k;
    scanf("%d", &k);

    int * p = (int *)malloc(k * sizeof(int));
    int i = 0;
    for (i = 0; i < k; i++) {
        scanf("%d", p + i);
    }

    int ThisSum = 0, ThisBegin = 0;
    int MaxSum = p[0], MaxBegin = 0, MaxEnd = 0;
    for (i = 0; i < k; i++) {
        ThisSum += p[i];
        if (ThisSum > MaxSum) {
            MaxSum = ThisSum;
            MaxBegin = ThisBegin;
            MaxEnd = i;
        } else if(ThisSum < 0) {
            ThisSum = 0;
            ThisBegin = i + 1;
        }
    }

    if (MaxSum < 0) {
        printf("0 %d %d", p[0], p[k-1]);    
    } else {
        printf("%d %d %d", MaxSum, p[MaxBegin], p[MaxEnd]);
    }
    return 0;
}
