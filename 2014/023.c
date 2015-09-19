#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHAR 0
#define DOUBLE 1

double compute(char op, double op1, double op2)
{
    switch(op) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
        case '*':
            return op1 * op2;
        case '/':
            if (op2 == 0) {
                printf("ERROR");
                exit(0);
            } else {
                return op1 / op2;
            }
    }
}

int main()  
{
    char exp[30][30];
    int count = 0;
    while (scanf("%s", exp[count]) != EOF) {
        count++;
    }

    typedef struct node {
        int type;
        union {
            char c;
            double d;
        } u;
        struct node *next;
    } Node;
    Node head;
    head.next = NULL;
    Node *temp = &head;

    int i = 0;
    int len;
    for (i = 0; i < count; i++) {
        temp->next = (Node *)malloc(sizeof(Node));
        temp = temp->next;
        temp->next = NULL;
        len = strlen(exp[i]);
        if (len > 1) {
            temp->type = DOUBLE;
            temp->u.d = atof(exp[i]);
        } else if (len == 1) {
            if (isdigit(exp[i][0])) {
                temp->type = DOUBLE;
                temp->u.d = atof(exp[i]);  
            } else {
                temp->type = CHAR;
                temp->u.c = exp[i][0];
            }
        }
    }

    Node *op1, *op2;

    while (count >= 3) {
        temp = &head;
        while (temp->next != NULL) {
            temp = temp->next;
            if (temp->type == CHAR) {
                if (temp->next != NULL) {
                    op1 = temp->next;
                    if (op1->type == DOUBLE && op1->next != NULL) {
                        op2 = op1->next;
                        if (op2->type == DOUBLE) {
                            temp->type = DOUBLE;
                            temp->u.d = compute(temp->u.c, op1->u.d, op2->u.d);
                            temp->next = op2->next;
                            free(op1);
                            free(op2);
                            count -= 2;
                       }
                    }
                }
            }
        }
    }

    temp = head.next;
    if (temp->next == NULL && temp->type == DOUBLE) {
        printf("%.1lf", temp->u.d);
    }
    
    return 0;  
} 