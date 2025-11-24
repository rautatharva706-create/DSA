#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge_asr {
    int src_asr, dest_asr, weight_asr;
};

struct Node_asr {
    int dest_asr, weight_asr;
};

struct Set_asr {
    int parent_asr;
    int rank_asr;
};

int findSet_asr(vector<Set_asr> &set_asr, int v_asr) {
    if (set_asr[v_asr].parent_asr != v_asr)
        set_asr[v_asr].parent_asr = findSet_asr(set_asr, set_asr[v_asr].parent_asr);
    return set_asr[v_asr].parent_asr;
}

void unionSet_asr(vector<Set_asr> &set_asr, int u_asr, int v_asr) {
    int uRoot_asr = findSet_asr(set_asr, u_asr);
    int vRoot_asr = findSet_asr(set_asr, v_asr);

    if (set_asr[uRoot_asr].rank_asr < set_asr[vRoot_asr].rank_asr)
        set_asr[uRoot_asr].parent_asr = vRoot_asr;
    else if (set_asr[uRoot_asr].rank_asr > set_asr[vRoot_asr].rank_asr)
        set_asr[vRoot_asr].parent_asr = uRoot_asr;
    else {
        set_asr[vRoot_asr].parent_asr = uRoot_asr;
        set_asr[uRoot_asr].rank_asr++;
    }
}

int main() {
    int V_asr, E_asr;
    cout << "Enter number of vertices: ";
    cin >> V_asr;
    cout << "Enter number of edges: ";
    cin >> E_asr;

    vector<vector<Node_asr>> adjList_asr(V_asr);
    vector<Edge_asr> edges_asr;

    cout << "Enter edges (src dest weight):\n";
    for (int i = 0; i < E_asr; i++) {
        int u_asr, v_asr, w_asr;
        cin >> u_asr >> v_asr >> w_asr;

        adjList_asr[u_asr].push_back({v_asr, w_asr});
        adjList_asr[v_asr].push_back({u_asr, w_asr});

        edges_asr.push_back({u_asr, v_asr, w_asr});
    }

    sort(edges_asr.begin(), edges_asr.end(), [](Edge_asr a, Edge_asr b) {
        return a.weight_asr < b.weight_asr;
    });

    vector<Set_asr> set_asr(V_asr);
    for (int i = 0; i < V_asr; i++) {
        set_asr[i].parent_asr = i;
        set_asr[i].rank_asr = 0;
    }

    vector<Edge_asr> mst_asr;
    int totalCost_asr = 0;

    for (auto &edge_asr : edges_asr) {
        int uRoot_asr = findSet_asr(set_asr, edge_asr.src_asr);
        int vRoot_asr = findSet_asr(set_asr, edge_asr.dest_asr);

        if (uRoot_asr != vRoot_asr) {
            mst_asr.push_back(edge_asr);
            totalCost_asr += edge_asr.weight_asr;
            unionSet_asr(set_asr, uRoot_asr, vRoot_asr);
        }
    }

    cout << "\nMinimum Spanning Tree:\n";
    for (auto &edge_asr : mst_asr) {
        cout << edge_asr.src_asr << " -- " << edge_asr.dest_asr
             << "  Weight: " << edge_asr.weight_asr << endl;
    }

    cout << "Total Cost: " << totalCost_asr << endl;

    return 0;
}
