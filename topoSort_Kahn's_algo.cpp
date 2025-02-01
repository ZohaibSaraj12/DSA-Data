// Kahn's Algorithm 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjList;  // Adjacency List representation
    vector<int> inDegree;         // To store in-degree of nodes

    // Function to add a directed edge from u to v
    void addEdge(int u, int v) {
        if (adjList.size() <= u) {
            adjList.resize(u + 1);  // Resize if needed
            inDegree.resize(u + 1, 0);  // Ensure inDegree size matches
        }
        if (adjList.size() <= v) {
            adjList.resize(v + 1);
            inDegree.resize(v + 1, 0);
        }

        adjList[u].push_back(v);  // Add edge u -> v
        inDegree[v]++;            // Increment in-degree of vertex v
    }

    // Function to perform Topological Sort using Kahn's Algorithm
    void topologicalSort(int vertices) {

        queue<int> q;
        vector<int> topoOrder;
        cout << "its working" << endl;
        // Step 1: Enqueue nodes with in-degree 0 (no dependencies)
        for (int i = 0; i < vertices; i++) {
            cout << "step 1 working inside loop"  << i<< endl;
            if (inDegree[i] == 0) {
                cout << "inside if"  << i << endl;
                q.push(i);
            }
        }
        
        cout << "step 2 working" << endl;
        // Step 2: Process the nodes in the queue
        while (!q.empty()) {
            cout << "step 2 working inside while" << endl;
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);  // Add node to the result list

            // Decrease in-degree of all neighbors
            for (int neighbor : adjList[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);  // Add to queue if in-degree becomes 0
                }
            }
        }

        // Step 3: Check for cycle (if topoOrder doesn't contain all nodes)
        if (topoOrder.size() != vertices) {
            cout << "There exists a cycle in the graph!" << endl;
            return;
        }

        // Output the topological order
        cout << "Topological Sort: ";
        for (int node : topoOrder) {
            cout << node + 1 << " ";  // Converting to 1-based indexing for output
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    
    int n, m;
    cout << "Enter the number of vertices (n): ";
    cin >> n;
    cout << "Enter the number of edges (m): ";
    cin >> m;

    // Input the edges
    cout << "Enter " << m << " directed edges (from -> to):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u - 1, v - 1);  // Convert to 0-based indexing
    }

    // Perform Topological Sort
    g.topologicalSort(n);

    return 0;
}
