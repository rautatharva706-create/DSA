#include <iostream>
#include <queue>
using namespace std;

struct Graph_asr {
    int vertices_asr;
    int **adj_asr;
};

// Create graph
Graph_asr* createGraph_asr(int vertices_asr) {
    Graph_asr* graph_asr = new Graph_asr();
    graph_asr->vertices_asr = vertices_asr;

    graph_asr->adj_asr = new int*[vertices_asr];
    for (int i_asr = 0; i_asr < vertices_asr; i_asr++) {
        graph_asr->adj_asr[i_asr] = new int[vertices_asr];
        for (int j_asr = 0; j_asr < vertices_asr; j_asr++) {
            graph_asr->adj_asr[i_asr][j_asr] = 0;
        }
    }
    return graph_asr;
}
// Add edge
void addEdge_asr(Graph_asr* graph_asr, int u_asr, int v_asr) {
    graph_asr->adj_asr[u_asr][v_asr] = 1;
    graph_asr->adj_asr[v_asr][u_asr] = 1;  // Undirected
}
// BFS
void BFS_asr(Graph_asr* graph_asr, int start_asr) {
    int visited_asr[100] = {0};
    queue<int> q_asr;

    visited_asr[start_asr] = 1;
    q_asr.push(start_asr);

    cout << "BFS Traversal: ";

    while (!q_asr.empty()) {
        int curr_asr = q_asr.front();
        q_asr.pop();
        cout << curr_asr << " ";

        for (int i_asr = 0; i_asr < graph_asr->vertices_asr; i_asr++) {
            if (graph_asr->adj_asr[curr_asr][i_asr] == 1 && !visited_asr[i_asr]) {
                visited_asr[i_asr] = 1;
                q_asr.push(i_asr);
            }
        }
    }
    cout << endl;
}
// DFS Utility
void DFSUtil_asr(Graph_asr* graph_asr, int vertex_asr, int visited_asr[]) {
    visited_asr[vertex_asr] = 1;
    cout << vertex_asr << " ";

    for (int i_asr = 0; i_asr < graph_asr->vertices_asr; i_asr++) {
        if (graph_asr->adj_asr[vertex_asr][i_asr] == 1 && !visited_asr[i_asr]) {
            DFSUtil_asr(graph_asr, i_asr, visited_asr);
        }
    }
}
// DFS
void DFS_asr(Graph_asr* graph_asr, int start_asr) {
    int visited_asr[100] = {0};
    cout << "DFS Traversal: ";
    DFSUtil_asr(graph_asr, start_asr, visited_asr);
    cout << endl;
}

// print Adjacency Matrix
void printAdjacencyMatrix_asr(Graph_asr* graph_asr) {
    cout << "\nAdjacency Matrix:\n";
    for (int i_asr = 0; i_asr < graph_asr->vertices_asr; i_asr++) {
        for (int j_asr = 0; j_asr < graph_asr->vertices_asr; j_asr++) {
            cout << graph_asr->adj_asr[i_asr][j_asr] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices_asr, edges_asr;
    cout << "Enter number of vertices: ";
    cin >> vertices_asr;
    Graph_asr* graph_asr = createGraph_asr(vertices_asr);
    cout << "Enter number of edges: ";
    cin >> edges_asr;
    cout << "Enter edges (u v):" << endl;
    for (int i_asr = 0; i_asr < edges_asr; i_asr++) {
        int u_asr, v_asr;
        cin >> u_asr >> v_asr;
        addEdge_asr(graph_asr, u_asr, v_asr);
    }
    printAdjacencyMatrix_asr(graph_asr);
    int start_asr;
    cout << "\nEnter starting vertex for BFS and DFS: ";
    cin >> start_asr;
    BFS_asr(graph_asr, start_asr);
    DFS_asr(graph_asr, start_asr);
    return 0;
}
