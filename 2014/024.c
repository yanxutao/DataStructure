#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	int i;
	char t[10][2];
	for (i = 0; i < n; i++) {
		scanf("%c %c", &t[i][0], &t[i][1]);
	}

	for (i = 0; i < n; i++) {
		printf("%c %c\n", t[i][0], t[i][1]);
	}
	return 0;
}