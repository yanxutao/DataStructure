#include <stdio.h>
#include <stdlib.h>
#define ElementType int

typedef struct tnode *TreePtr;
typedef struct tnode {
	TreePtr parent;
	ElementType data;
	TreePtr child[2];
} TreeNode;

int main()
{
	int n;
	scanf("%d", &n);
	int i, j;
	char input[2];
	TreePtr tree = (TreePtr)malloc(n * sizeof(TreeNode));

	for (i = 0; i < n; i++) {
		scanf("%1s %1s", &input[0], &input[1]);
		tree[i].data = i;
		for (j = 0; j < 2; j++) {
			if (input[j] == '-') {
				tree[i].child[j] = NULL;
			} else {
				tree[i].child[j] = &tree[input[j] - '0'];
				tree[input[j] - '0'].parent = &tree[i];
			}
		}
	}

	TreePtr p = &tree[0], root;
	while (p->parent != NULL) {
		p = p->parent;
	}
	root = p;

	if (root != NULL) {
		TreePtr *queue = (TreePtr *)malloc(n * sizeof(TreePtr));
		queue[0] = root;
		i = 0;
		j = 1;
		int flag = 0;
		while (i < j) {
			p = queue[i++];
			if (p->child[0] == NULL && p->child[1] == NULL) {
				if (flag == 1)
					printf(" %d", p->data);
				else {
					printf("%d", p->data);
					flag = 1;
				}
			}
			if (p->child[0]) {
				queue[j++] = p->child[0];
			}
			if (p->child[1]) {
				queue[j++] = p->child[1];
			}
		}
	}

	return 0;
}