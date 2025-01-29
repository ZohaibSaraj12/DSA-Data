#include <iostream>
#include <map>
#include <list>
using namespace std;

class Graph {
public:
    map<int, list<int>> adjList;

    // Function to add an edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Function to display the graph
    void displayGraph() {
        for (const auto& pair : adjList) {
            cout << "Vertex " << pair.first << " is connected to: ";
            for (int neighbor : pair.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    // Get the number of vertices and edges
    int n, m;
    cout << "Enter the number of vertices (n): ";
    cin >> n;
    cout << "Enter the number of edges (m): ";
    cin >> m;

    // Get the edges from the user
    cout << "Enter " << m << " edges (as pairs of vertices):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        g.addEdge(u, v);  // Add the edge to the graph
    }

    // Display the adjacency list representation of the graph
    g.displayGraph();

    return 0;
}
