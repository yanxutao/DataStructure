#include <stdio.h>

int main()
{
    int k;
    scanf("%d", &k);
    int i;
    int d;
    int max = 0;
    int tmp = 0;
    for (i = 0; i < k; i++) {
        scanf("%d", &d);
        tmp += d;
        if (tmp < 0) {
            tmp = 0;
        } else if (tmp > max)
            max = tmp;
    }
        
    printf("%d", max);

    return 0;
}