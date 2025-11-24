#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure for storing graph edges
struct Edge_asr {
    int vertex_asr;
    int weight_asr;
};

// Structure for priority queue nodes
struct Node_asr {
    int vertex_asr;
    int dist_asr;
};

// Custom comparator
struct Compare_asr {
    bool operator()(Node_asr const &a_asr, Node_asr const &b_asr) {
        return a_asr.dist_asr > b_asr.dist_asr;
    }
};

int main() {
    int vertices_asr, edges_asr;
    cout << "Enter number of vertices: ";
    cin >> vertices_asr;

    cout << "Enter number of edges: ";
    cin >> edges_asr;

    vector<vector<Edge_asr>> adj_asr(vertices_asr);

    cout << "Enter edges (u v w):\n";
    for(int i_asr = 0; i_asr < edges_asr; i_asr++) {
        int u_asr, v_asr, w_asr;
        cin >> u_asr >> v_asr >> w_asr;

        Edge_asr edge1_asr = {v_asr, w_asr};
        adj_asr[u_asr].push_back(edge1_asr);

        Edge_asr edge2_asr = {u_asr, w_asr}; // For undirected graph
        adj_asr[v_asr].push_back(edge2_asr);
    }

    int source_asr;
    cout << "Enter source vertex: ";
    cin >> source_asr;

    vector<int> dist_asr(vertices_asr, INT_MAX);
    vector<bool> visited_asr(vertices_asr, false);

    priority_queue<Node_asr, vector<Node_asr>, Compare_asr> pq_asr;

    dist_asr[source_asr] = 0;

    pq_asr.push({source_asr, 0});

    while(!pq_asr.empty()) {
        Node_asr top_asr = pq_asr.top();
        pq_asr.pop();

        int u_asr = top_asr.vertex_asr;

        if(visited_asr[u_asr]) {
            continue;
        }

        visited_asr[u_asr] = true;

        for(auto edge_asr : adj_asr[u_asr]) {
            int v_asr = edge_asr.vertex_asr;
            int weight_asr = edge_asr.weight_asr;

            if(dist_asr[u_asr] + weight_asr < dist_asr[v_asr]) {
                dist_asr[v_asr] = dist_asr[u_asr] + weight_asr;
                pq_asr.push({v_asr, dist_asr[v_asr]});
            }
        }
    }

    cout << "\nShortest distances from source " << source_asr << ":\n";
    for(int i_asr = 0; i_asr < vertices_asr; i_asr++) {
        cout << "Vertex " << i_asr << " : " << dist_asr[i_asr] << endl;
    }

    return 0;
}