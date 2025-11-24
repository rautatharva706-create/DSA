#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Edge_asr {
    int to_asr;
    int weight_asr;
};

struct Node_asr {
    int vertex_asr;
    int key_asr;
    bool operator>(const Node_asr &other_asr) const {
        return key_asr > other_asr.key_asr;
    }
};

int main() {
    int vertices_asr, edges_asr;
    cout << "Enter number of vertices: ";
    cin >> vertices_asr;

    cout << "Enter number of edges: ";
    cin >> edges_asr;

    vector<vector<Edge_asr>> adjList_asr(vertices_asr);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < edges_asr; i++) {
        int u_asr, v_asr, w_asr;
        cin >> u_asr >> v_asr >> w_asr;
        adjList_asr[u_asr].push_back({v_asr, w_asr});
        adjList_asr[v_asr].push_back({u_asr, w_asr});
    }

    vector<int> key_asr(vertices_asr, INT_MAX);
    vector<bool> inMST_asr(vertices_asr, false);
    vector<int> parent_asr(vertices_asr, -1);

    priority_queue<Node_asr, vector<Node_asr>, greater<Node_asr>> pq_asr;

    key_asr[0] = 0;
    pq_asr.push({0, 0});

    while (!pq_asr.empty()) {
        int u_asr = pq_asr.top().vertex_asr;
        pq_asr.pop();

        if (inMST_asr[u_asr]) continue;
        inMST_asr[u_asr] = true;

        for (auto &edge_asr : adjList_asr[u_asr]) {
            int v_asr = edge_asr.to_asr;
            int w_asr = edge_asr.weight_asr;

            if (!inMST_asr[v_asr] && w_asr < key_asr[v_asr]) {
                key_asr[v_asr] = w_asr;
                parent_asr[v_asr] = u_asr;
                pq_asr.push({v_asr, key_asr[v_asr]});
            }
        }
    }

    cout << "\nMinimum Spanning Tree:\n";
    for (int i = 1; i < vertices_asr; i++) {
        cout << parent_asr[i] << " - " << i << " (Weight: " << key_asr[i] << ")\n";
    }

    return 0;
}