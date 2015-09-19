#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char begin[5];
	int n, k;
	scanf("%s %d %d", begin, &n, &k);
	
	typedef struct node *lineptr;
	typedef struct node
	{
		char address[5];
		int data;
		char next[5];
		int valid;
	}line;

	lineptr input = (lineptr)malloc(n * (sizeof(line)));
	//lineptr link = (lineptr)malloc(n * sizeof(lineptr));
	int *link = (int *)malloc(n * sizeof(int));
	
	int i;
	for (i = 0; i < n; i++) {
		scanf("%s", input[i].address);
		scanf("%d", &input[i].data);
		scanf("%s", input[i].next); 
		input[i].valid = 1;
	}

	int j;
	char *p = begin;
	for (j = 0; j < n; j++) {
		for (i = 0; i < n; i++) {
			if (input[i].valid == 1){ 
				if (strcmp(p, input[i].address) == 0) {
					link[j] = i;
					p =  input[i].next; 
					input[i].valid = 0;
					break;
				}
			}
		}
	}

	int *newlink = (int *)malloc(n * sizeof(int));
	int l = 0;
	int c, m;
	c = n / k;
	m = n % k;
	for (i = 0; i < c; i++) {
		for (j = k - 1 + i * k; j >= i * k; j--) {
			newlink[l++] = link[j];
		}
	}

	for (i = 0; i < m; i++) {
		newlink[l++] = link[c * k + i];
	}

	for (i = 0; i < n - 1; i++) {
		strcpy(input[newlink[i]].next, input[newlink[i + 1]].address);
	}

	strcpy(input[newlink[n-1]].next, "-1");

	for (i = 0; i < n; i++) {
		printf("%s ", input[newlink[i]].address);
		printf("%d ", input[newlink[i]].data);
		printf("%s\n", input[newlink[i]].next);
	}

	return 0;
}