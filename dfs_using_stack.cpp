#include <iostream>
#include <vector>
#include <stack>
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
        adjList[v].push_back(u);  // Undirected graph
    }

    void dfs(int start) {
        vector<bool> visited(vertices, false);
        stack<int> s;

        s.push(start);
        
        cout << "DFS Traversal using stack: ";

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                visited[node] = true;
                cout << node << " ";

                // Push unvisited neighbors onto the stack
                for (int neighbor : adjList[node]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
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
