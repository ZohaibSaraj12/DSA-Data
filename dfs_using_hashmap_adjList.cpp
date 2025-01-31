#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

class Graph {
    unordered_map<int, list<int>> adjList;

public:
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // For undirected graph
    }

    void dfsHelper(int node, unordered_map<int, bool>& visited) {
        visited[node] = true;
        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfsHelper(neighbor, visited);
            }
        }
    }

    void dfs(int start) {
        unordered_map<int, bool> visited;
        cout << "DFS Traversal starting from node " << start << ": ";
        dfsHelper(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g;

    // Dynamically adding nodes and edges
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    g.dfs(1);

    return 0;
}
