#include <stdio.h>

double a3, a2, a1, a0;

double f(double x)
{
	return a3 * x * x * x + a2 * x * x + a1 * x + a0; 
}

int main()
{
	double a, mid, b;
	scanf("%lf %lf %lf %lf %lf %lf", &a3, &a2, &a1, &a0, &a, &b);
	while (b - a > 0.01) {
		mid = (a + b) / 2;
		if (f(mid) == 0) {
			printf("%.2lf", mid);			
			return 0;
		} else if (f(a) * f(mid) < 0) {
			b = mid;
		} else {
			a = mid;
		}
	}

	printf("%.2lf", (a + b) / 2);
	return 0;
}