#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int vertices;  
    vector<vector<int>> adjList;  

public:
    Graph(int v) : vertices(v) {
        adjList.resize(v);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // For undirected graph
    }

    void dfsHelper(int node, vector<bool>& visited) {
        visited[node] = true;
        cout << node << " ";  

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
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
