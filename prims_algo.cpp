#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    int V;
    vector<vector<pair<int, int>>> adjList;  // Pair: {vertex, weight}

public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight});  // Undirected graph
    }

    void primMST() {
        vector<int> key(V, INT_MAX);  // To store minimum weights
        vector<bool> inMST(V, false); // Track vertices included in MST
        vector<int> parent(V, -1);    // Store MST structure

        key[0] = 0;  // Start from the first vertex

        for (int count = 0; count < V - 1; count++) {
            int minKey = INT_MAX;
            int u;

            // Find the vertex with the minimum key value not yet in MST
            for (int v = 0; v < V; v++) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            inMST[u] = true;  // Include selected vertex in MST

            // Update adjacent vertices
            for (auto &[v, weight] : adjList[u]) {
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }

        // Print the MST
        cout << "Edge \tWeight\n";
        for (int i = 1; i < V; i++) {
            cout << parent[i] << " - " << i << "\t" << key[i] << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter edges (U V Weight):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    g.primMST();

    return 0;
}
// 0 1 6 0 3 2 1 2 4 1 3 8 2 3 7