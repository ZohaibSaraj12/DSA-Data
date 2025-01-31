#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int vertices;
    vector<vector<int>> adjMatrix;

public:
    Graph(int v) : vertices(v) {
        adjMatrix.resize(v, vector<int>(v, 0));  // Initialize matrix with 0
    }

    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // For undirected graph
    }

    void dfsHelper(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                dfsHelper(i, visited);
            }
        }
    }

    void dfs(int start) {
        vector<bool> visited(vertices, false);
        cout << "DFS Traversal starting from node " << start << ": ";
        dfsHelper(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(5);  // 5 vertices (0 to 4)

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    g.dfs(0);

    return 0;
}
