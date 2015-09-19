#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int i, j;
    int min, max;
    int p, q;
    int flag;

    for (i = 0; i < n; i++) {
        j = 1;
        min = 1;
        max = m;
        flag = 1;
        scanf("%d", &p);
        while (j < m) {
            scanf("%d", &q);
            if (q < min || q > max)
                flag = 0;
            else if (q < p)
                max = (p < max) ? p : max;
            else if (q > p)
                min = (p > min) ? p : min;
            p = q;
            j++;
        }
        if (flag == 0)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}