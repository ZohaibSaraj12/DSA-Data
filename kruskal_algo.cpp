#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Disjoint Set (Union-Find) class
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union by rank
    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
vector<vector<int>> kruskal(int n, vector<vector<int>>& edges) {
    DisjointSet ds(n);
    vector<vector<int>> mst;

    // Sort edges by weight (edges[i][2] is the weight)
    sort(edges.begin(), edges.end(), [](vector<int>& e1, vector<int>& e2) {
        return e1[2] < e2[2];
    });

    for (vector<int>& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        // If u and v belong to different sets, add the edge to MST
        if (ds.find(u) != ds.find(v)) {
            mst.push_back(edge);
            ds.unionSets(u, v);
        }
    }

    return mst;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> edges;

    cout << "Enter the edges (u, v, weight) one by one:\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    vector<vector<int>> mst = kruskal(n, edges);

    cout << "Minimum Spanning Tree (MST):\n";
    for (vector<int>& edge : mst) {
        cout << edge[0] << " - " << edge[1] << " with weight " << edge[2] << endl;
    }

    return 0;
}
