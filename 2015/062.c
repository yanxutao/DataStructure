
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PointType double

struct point {
    PointType x;
    PointType y;
} Position[100];

int visited[100];
int n;
double d;
int answer;

int IsSafe(int i)
{
    int x, y;
    x = Position[i].x;
    y = Position[i].y;
    if (50 - x <= d || x + 50 <= d || 50 - y <= d || y + 50 <= d)
        return 1;
    return 0;
}

int FirstJump(int i)
{
    int x, y;
    x = Position[i].x;
    y = Position[i].y;
    if (sqrt(x * x + y * y) <= d + 15)
        return 1;
    return 0;
}

int Jump(int i, int j)
{
    int x1, y1, x2, y2;
    x1 = Position[i].x;
    y1 = Position[i].y;
    x2 = Position[j].x;
    y2 = Position[j].y;
    if (sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) <= d)
        return 1;
    return 0;
}

int DFS(int i)
{
    visited[i] = 1;
    if (IsSafe(i)) answer = 1;
    else {
        int j;
        for (j = 0; j < n; j++)
            if (!visited[j] && Jump(i, j)) {
                answer = DFS(j);
                if (answer == 1) break;
            }
    }
    return answer;
}

int main()
{
    scanf("%d %lf", &n, &d);
    int i;
    for (i = 0; i < n; i++) {
        scanf("%lf %lf", &Position[i].x, &Position[i].y);
        visited[i] = 0;
    }

    answer = 0;

    for (i = 0; i < n; i++) {
        if (!visited[i] && FirstJump(i)) {
            answer = DFS(i);
            if (answer == 1) break;
        }
    }

    if (answer == 1) printf("Yes");
    else printf("No");
    return 0;
}