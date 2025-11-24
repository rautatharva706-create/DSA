#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Structure for graph node
struct GraphNode_asr {
    int vertex_asr;
    GraphNode_asr* next_asr;
};

// Function to create a new graph node
GraphNode_asr* createNode_asr(int vertex_asr) {
    GraphNode_asr* node_asr = new GraphNode_asr();
    node_asr->vertex_asr = vertex_asr;
    node_asr->next_asr = nullptr;
    return node_asr;
}

// Function to add edge to the adjacency list
void addEdge_asr(vector<GraphNode_asr*>& adjList_asr, int u_asr, int v_asr) {
    GraphNode_asr* node_asr = createNode_asr(v_asr);
    node_asr->next_asr = adjList_asr[u_asr];
    adjList_asr[u_asr] = node_asr;

    node_asr = createNode_asr(u_asr); // For undirected graph
    node_asr->next_asr = adjList_asr[v_asr];
    adjList_asr[v_asr] = node_asr;
}

// BFS traversal
void BFS_asr(vector<GraphNode_asr*>& adjList_asr, int start_asr, int V_asr) {
    vector<bool> visited_asr(V_asr, false);
    queue<int> q_asr;
    visited_asr[start_asr] = true;
    q_asr.push(start_asr);

    cout << "BFS Traversal: ";
    while(!q_asr.empty()) {
        int v_asr = q_asr.front();
        q_asr.pop();
        cout << v_asr << " ";

        GraphNode_asr* temp_asr = adjList_asr[v_asr];
        while(temp_asr) {
            if(!visited_asr[temp_asr->vertex_asr]) {
                visited_asr[temp_asr->vertex_asr] = true;
                q_asr.push(temp_asr->vertex_asr);
            }
            temp_asr = temp_asr->next_asr;
        }
    }
    cout << endl;
}

// DFS traversal
void DFSUtil_asr(vector<GraphNode_asr*>& adjList_asr, int v_asr, vector<bool>& visited_asr) {
    visited_asr[v_asr] = true;
    cout << v_asr << " ";

    GraphNode_asr* temp_asr = adjList_asr[v_asr];
    while(temp_asr) {
        if(!visited_asr[temp_asr->vertex_asr]) {
            DFSUtil_asr(adjList_asr, temp_asr->vertex_asr, visited_asr);
        }
        temp_asr = temp_asr->next_asr;
    }
}

void DFS_asr(vector<GraphNode_asr*>& adjList_asr, int start_asr, int V_asr) {
    vector<bool> visited_asr(V_asr, false);
    cout << "DFS Traversal: ";
    DFSUtil_asr(adjList_asr, start_asr, visited_asr);
    cout << endl;
}

int main() {
    int V_asr, E_asr;
    cout << "Enter number of vertices: ";
    cin >> V_asr;
    cout << "Enter number of edges: ";
    cin >> E_asr;

    vector<GraphNode_asr*> adjList_asr(V_asr, nullptr);

    cout << "Enter edges (u v):" << endl;
    for(int i = 0; i < E_asr; i++) {
        int u_asr, v_asr;
        cin >> u_asr >> v_asr;
        addEdge_asr(adjList_asr, u_asr, v_asr);
    }

    int start_asr;
    cout << "Enter starting vertex: ";
    cin >> start_asr;

    BFS_asr(adjList_asr, start_asr, V_asr);
    DFS_asr(adjList_asr, start_asr, V_asr);

    return 0;
}
