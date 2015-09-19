#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char ch;
    scanf("%d %c", &n, &ch);

    int s, l;
    int i = 1;
    while (i) {
        if ((n >= 2 * i * i - 1) && (n < 2 * (i + 1) * (i + 1) - 1))
            break;
        i++;
    }

    s = 2 * i * i - 1;
    l = 2 * i - 1;

    char *c = (char *)malloc(l * (l + 1) * sizeof(char));

    int j;

    for (i = 0; i < l; i++) {
        for (j = 0; j < l; j++){
            c[i * (l + 1) + j] = ' ';
        }
    }

    for (i = 0; i < l / 2; i++) {
        for (j = i; j < l - i; j++) {
            c[i * (l + 1) + j] = ch;
        }
        c[i * (l + 1) + j] = '\n';
    }

    c[(l / 2) * (l + 1) + (l / 2)] = ch;
    c[(l / 2) * (l + 1) + (l / 2) + 1] = '\n';

    for (i =  l / 2 + 1; i < l; i++) {
        for (j = l - i - 1; j <= i; j++) {
            c[i * (l + 1) + j] = ch;
        }
        c[i * (l + 1) + j] = '\n';
    }

    for (i = 0; i < l; i++) {
        for (j = 0; j < l + 1; j++){
            printf("%c", c[i * (l + 1) + j]);
            if (c[i * (l + 1) + j] == '\n')
                break;
        }
    }

    printf("%d\n", n - s);
    return 0;
}