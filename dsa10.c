#include <stdio.h>
#define MAX 10
int graph[MAX][MAX];
int visited[MAX];
int n;
void BFS(int start)
{
    int queue[MAX];
    int front = 0, rear = 0;
    int i, v;

    for (i = 0; i < n; i++)
        visited[i] = 0;
    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS Traversal: ");
    while (front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}
void DFS(int v)
{
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}
int main()
{
    int i, j, choice, start;

    printf("Enter number of vertices (max 10): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of vertices\n");
        return 0;
    }

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    if (start < 0 || start >= n)
    {
        printf("Invalid starting vertex\n");
        return 0;
    }
    printf("\n1. BFS\n");
    printf("2. DFS\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        BFS(start);
    }
    else if (choice == 2)
    {
        for (i = 0; i < n; i++)
            visited[i] = 0;

        printf("DFS Traversal: ");
        DFS(start);
        printf("\n");
    }
    else
    {
        printf("Invalid choice\n");
    }
    return 0;
}
