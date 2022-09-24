/*Construct a Minimum spanning tree using Prim's algorithm.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int a, b, u, v, n, i, j, ne = 1;
int visited[MAX], min, mincost = 0, cost[MAX][MAX];
int main()
{
    printf("\nEnter the number of nodes:");
    scanf("%d", &n);
    printf("\n");
    printf("\nEnter the adjacency matrix: ");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    visited[1] = 1;
    printf("\nEnter the source node:");
    scanf("%d", &a);
    printf("\nEnter the destination node:");
    scanf("%d", &b);
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min)
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("Enter the edge %d:(%d %d) cost:%d\n", ne++, a, b, min);

            mincost += min;
            visited[b] = 1;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("Minimum cost=%d\n", mincost);
    return 0;
}
