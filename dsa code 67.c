/*Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

// Push to stack
void push(int v) {
    stack[++top] = v;
}

// DFS function
void DFS(int v) {
    visited[v] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }

    // Push after visiting all neighbors
    push(v);
}

// Topological Sort
void topoSort() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    printf("Topological Ordering: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    topoSort();

    return 0;
}