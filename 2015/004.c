#include <stdio.h>

int main()
{
    char s[20], d[20];
    gets(s);

    int n;
    for (n = 0; s[n] != '\0'; n++);

    int i;
    int sc[10], dc[10];

    for (i = 0; i < 10; i++) {
        sc[i] = dc[i] = 0;
    }

    int c = 0, sum;
    for (i = n - 1; i >= 0; i--) {
        sum = 2 * (s[i] - '0') + c;
        c = sum / 10;
        d[i] = sum % 10 + '0';
    }
    d[n] = '\0';

    for (i = 0; i < n; i++) {
        sc[s[i] - '0']++;
        dc[d[i] - '0']++;
    }

    if (c == 1) {
        printf("No\n%d%s", c, d);
        return 0;
    }

    for (i = 0; i < 10; i++) {
        if (sc[i] != dc[i]) {
            printf("No\n%s", d);
            return 0;
        }
    }

    printf("Yes\n%s", d);
    return 0;
}