#include <iostream>
#include <vector>

class Graph {
public:
    // Adjacency matrix representation (n x n)
    vector<vector<int>> adjMatrix;

    // Constructor to initialize the matrix with 0s
    Graph(int n) {
        adjMatrix.resize(n, vector<int>(n, 0));  // Create an n x n matrix with all 0s
    }

    // Function to add an edge between two vertices u and v
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;  // Add edge from u to v
        adjMatrix[v][u] = 1;  // Since it's an undirected graph, add the reverse edge
    }

    // Function to display the adjacency matrix
    void displayGraph() {
        for (int i = 0; i < adjMatrix.size(); ++i) {
            for (int j = 0; j < adjMatrix[i].size(); ++j) {
                cout << adjMatrix[i][j] << " ";  // Print each element in the matrix
            }
            cout << endl;
        }
    }
};

int main() {
    // Number of vertices in the graph
    int n = 4;
    Graph g(n);

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    // Display the adjacency matrix
    std::cout << "Adjacency Matrix:\n";
    g.displayGraph();

    return 0;
}
