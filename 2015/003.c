#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int *s = (int *)malloc(n * sizeof(int));
    int *d = (int *)malloc(n * sizeof(int));

    int i;
    for (i = 0; i < n; i++)
        scanf("%d", s + i);

    for (i = 0; i < n; i++)
        d[(i + m) % n] = s[i];

    for (i = 0; i < n - 1; i++)
        printf("%d ", d[i]);
    printf("%d", d[n - 1]);

    return 0;
}