#include <stdio.h>
#include <math.h>

int isprime(int n)
{
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int i;
    int c = 0;

    for (i = 2; i + 2 <= n; i++) {
        if (isprime(i) && isprime(i + 2)) {
            c++;
            i++;
        }
    }

    printf("%d", c);

    return 0;
}