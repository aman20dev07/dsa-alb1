#include <stdio.h>
#include <stdlib.h>

void creategraph(int n, int a[10][10]) {
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
}

void bfs(int a[10][10], int n, int source) {
    int visited[10] = {0}, queue[10], f = 0, r = 0;
    printf("Reachable nodes from %d: ", source);
    visited[source] = 1;
    queue[r++] = source;

    while (f < r) {
        int u = queue[f++];
        printf("%d ", u);
        for (int v = 0; v < n; v++)
            if (a[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[r++] = v;
            }
    }
    printf("\n");
}

int dfs(int a[10][10], int n, int visited[], int v) {
    visited[v] = 1;
    int count = 1;
    for (int i = 0; i < n; i++)
        if (a[v][i] && !visited[i])
            count += dfs(a, n, visited, i);
    return count;
}

int main() {
    int a[10][10], n, choice, source;
    int visited[10] = {0};  // Move this declaration outside the switch

    while (1) {
        printf("\n1: Create Graph\n2: BFS Reachability\n3: Check Connectivity\n4: Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            creategraph(n, a);
            break;

        case 2:
            printf("Enter source node 0 - %d ",n-1);
            scanf("%d", &source);
            bfs(a, n, source);
            break;

        case 3:
            printf(dfs(a, n, visited, 0) == n ? "Graph is connected\n" : "Graph is not connected\n");
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
        }
    }

   return 0;
}