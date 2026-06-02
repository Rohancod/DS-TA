#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Graph {
    int vertices;
    struct Node** adjList;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


struct Graph* createGraph(int v) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = v;

    graph->adjList = (struct Node**)malloc(v * sizeof(struct Node*));

    for (int i = 0; i < v; i++)
        graph->adjList[i] = NULL;

    return graph;
}


void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);

    if (graph->adjList[src] == NULL) {
        graph->adjList[src] = newNode;
    } else {
        struct Node* temp = graph->adjList[src];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    // Undirected graph
    newNode = createNode(src);

    if (graph->adjList[dest] == NULL) {
        graph->adjList[dest] = newNode;
    } else {
        struct Node* temp = graph->adjList[dest];
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}


void DFSUtil(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = graph->adjList[v];
    while (temp) {
        if (!visited[temp->data]) {
            DFSUtil(graph, temp->data, visited);
        }
        temp = temp->next;
    }
}

void DFS(struct Graph* graph, int start) {
    int visited[100] = {0};

    printf("DFS: ");
    DFSUtil(graph, start, visited);
    printf("\n");
}


void BFS(struct Graph* graph, int start) {
    int visited[100] = {0};
    int queue[100];
    int front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS: ");

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = graph->adjList[current];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->vertices; v++) {
        struct Node* temp = graph->adjList[v];
        printf("Vertex %d: ", v);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    struct Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    printGraph(graph);
    DFS(graph, 0);
    BFS(graph, 0);

    return 0;
}