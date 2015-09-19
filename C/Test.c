
#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAXN 10
#define MAXK 1e7

clock_t start, stop;
double duration;

double f1(int n, double a[], double x)
{
    int i;
    double p = a[0];
    for (i = 1; i <= n; i++) {
        p += a[i] * pow(x, i);
    }
    return p;
}


double f2(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for (i = n; i > 0; i--) {
        p = a[i - 1] + x * p;
    }
    return p;
}

int main()
{
    int i;
    double a[MAXN];
    for (i = 0; i < MAXN; i++) 
        a[i] = (double)i;

    start = clock();
    for (i = 0; i < MAXK; i++)
        f1(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start))/(CLOCKS_PER_SEC * MAXK);
    printf("ticks1 = %lf\n", (double)(stop - start));
    printf("duration1 = %6.2e\n", duration);

    start = clock();
    for (i = 0; i < MAXK; i++)
        f2(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)(stop - start))/(CLOCKS_PER_SEC * MAXK);
    printf("ticks2 = %lf\n", (double)(stop - start));
    printf("duration2 = %6.2e\n", duration);

    return 0;
}




#include <stdio.h>
#include <math.h>
#include <time.h>


void PrintN1(int N)
{
    int i;
    for (i = 1; i <= N; i++) {
        printf("%d\n", i);
    }
}


void PrintN2(int N)
{
    if (N) {
        PrintN(N - 1);
        printf("%d\n", N);
    }
}


double f1(int n, double a[], double x)
{
    int i;
    double p = a[0];
    for (i = 1; i <= n; i++) {
        p += a[i] * pow(x, i);
    }
    return p;
}


double f2(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for (i = n; i > 0; i--) {
        p = a[i - 1] + x * p;
    }
    return p;
}


double f3(int n, double a[], double x)
{
    int i;
    double p = a[0];
    double temp = 1;
    for (i = 1; i <= n; i++) {
        temp *= x;
        p += a[i] * temp;
    }
}


clock_t start, stop;
double duration;

int main()
{

    start = clock();

    int N;
    scanf("%d", &N);
    PrintN(N);

    stop = clock();

    duration = ((double)(stop - start))/CLK_TCK;

    return 0;
}


typedef struct PolyNode *Polynomial;
typedef struct PolyNode {
    int coef;
    int expon;
    Polynomial link;
};

typedef struct GNode {
    int Tag;
    union {
        ElementType Data;
        struct GNode *SubList;
    } URegion;
    struct GNode *next;
} GList;


int SequentialSearch(StaticTable *Tb1, ElementType K)
{
    int i;
    Tb1->Element[0] = K;
    for (i = Tb1->Length; Tb1->Element[i] != K; i--);
    return i;
}

int BinarySearch(StaticTable *Tb1, ElementType K)
{
    int left, right, mid, NotFound = -1;
    left = 1;
    right = Tb1->Length;
    while (left <= right) {
        mid = (left + right) / 2;
        if (K < Tb1->Element[mid])
            right = mid - 1;
        else if (K > Tb1->Element[mid])
            left = mid + 1;
        else
            return mid;
    }
    return NotFound;
}

