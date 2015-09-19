#include <stdio.h>
#include <math.h>

int main()
{
    int i;
    scanf("%d", &i);
//    printf("%lf\n", pow(2, i));
    printf("%lf\n", pow(4, i) - 3 * pow(2, i) + 1);
    return 0;
}
