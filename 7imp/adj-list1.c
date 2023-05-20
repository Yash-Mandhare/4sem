#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an edge in the adjacency list
void addEdge(struct Node** adjList, int src, int dest) {
    // Create a new node for the destination vertex
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Function to print the adjacency list
void printAdjList(struct Node** adjList, int numVertices) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < numVertices; i++) {
        printf("Vertex %d: ", i);
        struct Node* currNode = adjList[i];
        while (currNode) {
            printf("%d ", currNode->vertex);
            currNode = currNode->next;
        }
        printf("\n");
    }
}

// Function to calculate the degree of each vertex


int main() {
    struct Node* adjacencyList[MAX_VERTICES] = {NULL};
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

        // Add the edge to the adjacency list
        addEdge(adjacencyList, vertex1, vertex2);
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    printAdjList(adjacencyList, numVertices);
    

    return 0;
}
