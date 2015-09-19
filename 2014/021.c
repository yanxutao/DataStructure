#include <stdio.h>
#include <stdlib.h>

int main()
{
	int begin, n, k;
	scanf("%d %d %d", &begin, &n, &k);

	int input[100000][2];
	int address;
	int i, j;
	for (i = 0; i < n; i++) {
		scanf("%d", &address);
		scanf("%d %d", &input[address][0], &input[address][1]);
	}

	int *link = (int *)malloc(n * sizeof(int));
	int p = begin;
	int real = 0;
	while (p != -1) {
		link[real++] = p;
		p = input[p][1];
	}

	int *newlink = (int *)malloc(real * sizeof(int));
	int l = 0;
	int c, m;
	c = real / k;
	m = real - c * k;
	for (i = 0; i < c; i++) {
		for (j = k - 1 + i * k; j >= i * k; j--) {
			newlink[l++] = link[j];
		}
	}
	for (i = 0; i < m; i++) {
		newlink[l++] = link[c * k + i];
	}

	printf("%05d %d ", newlink[0], input[newlink[0]][0]);
	for (i = 1; i < real; i++)
		printf("%05d\n%05d %d ", newlink[i], newlink[i], input[newlink[i]][0]);
	printf("-1\n");

	return 0;
}