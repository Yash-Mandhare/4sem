#include <stdio.h>

#define MAX_VERTICES 10

void printDegree(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int indegree[MAX_VERTICES] = {0};
    int outdegree[MAX_VERTICES] = {0};
    int totalDegree[MAX_VERTICES] = {0};

    // Calculate the indegree, outdegree, and total degree for each vertex
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (adjacencyMatrix[i][j] == 1) {
                outdegree[i]++;
                indegree[j]++;
                totalDegree[i]++;
                totalDegree[j]++;
            }
        }
    }

    // Print the indegree, outdegree, and total degree for each vertex
    printf("\nVertex\tIndegree\tOutdegree\tTotal Degree\n");
    for (int i = 0; i < numVertices; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i, indegree[i], outdegree[i], totalDegree[i]);
    }
}

int main() {
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES] = {0};
    int numVertices, numEdges, i, j, vertex1, vertex2;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter the edges (vertex1 vertex2):\n");
    for (int k = 0; k < numEdges; k++) {
        scanf("%d %d", &vertex1, &vertex2);

        // Update the adjacency matrix for the edge
        adjacencyMatrix[vertex1][vertex2] = 1;
        adjacencyMatrix[vertex2][vertex1] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    printDegree(adjacencyMatrix, numVertices);

    return 0;
}


/*
Enter the number of vertices: 4
Enter the number of edges: 4
Enter the edges (vertex1 vertex2):
0 1
1 2
2 3
3 0

Adjacency Matrix:
0 1 0 0
1 0 1 0
0 1 0 1
0 0 1 0

Vertex  Indegree  Outdegree  Total Degree
0       1         1          2
1       2         2          4
2       2         2          4
3       2         2          4
*/ 