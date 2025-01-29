#include <iostream>
#include <vector>

class Graph {
public:
    // Adjacency list representation (no resize here, only push_back)
    std::vector<std::vector<int>> adjList;

    // Function to add an edge between two vertices u and v
    void addEdge(int u, int v) {
        // Ensure that the adjacency list has enough space to store the vertices
        if (adjList.size() <= u) {
            adjList.resize(u + 1);  // Resize only if needed (for higher indices)
        }
        if (adjList.size() <= v) {
            adjList.resize(v + 1);  // Resize only if needed (for higher indices)
        }

        // Add edge to adjacency list
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // As it's an undirected graph
    }

    // Function to display the graph
    void displayGraph() {
        // Loop through #include <iostream>
#include <vector>

class Graph {
public:
    // Adjacency list representation (no resize here, only push_back)
    std::vector<std::vector<int>> adjList;

    // Function to add an edge between two vertices u and v
    void addEdge(int u, int v) {
        // Ensure that the adjacency list has enough space to store the vertices
        if (adjList.size() <= u) {
            adjList.resize(u + 1);  // Resize only if needed (for higher indices)
        }
        if (adjList.size() <= v) {
            adjList.resize(v + 1);  // Resize only if needed (for higher indices)
        }

        // Add edge to adjacency list
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // As it's an undirected graph
    }

    // Function to display the graph
    void displayGraph() {
        // Loop through all the vertices
        for (int i = 0; i < adjList.size(); ++i) {
            std::cout << "Vertex " << i << " is connected to: ";
            for (int neighbor : adjList[i]) {
                std::cout << neighbor << " ";  // Print all neighbors of vertex i
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g;

    // Step 1: Get the number of vertices and edges
    int n, m;
    std::cout << "Enter the number of vertices (n): ";
    std::cin >> n;
    std::cout << "Enter the number of edges (m): ";
    std::cin >> m;

    // Step 2: Get the edges from the user
    std::cout << "Enter " << m << " edges (as pairs of vertices):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cout << "Edge " << i + 1 << ": ";
        std::cin >> u >> v;
        g.addEdge(u, v);  // Add the edge to the graph
    }

    // Step 3: Display the graph's adjacency list
    g.displayGraph();

    return 0;
}all the vertices
        for (int i = 0; i < adjList.size(); ++i) {
            std::cout << "Vertex " << i << " is connected to: ";
            for (int neighbor : adjList[i]) {
                std::cout << neighbor << " ";  // Print all neighbors of vertex i
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g;

    // Step 1: Get the number of vertices and edges
    int n, m;
    std::cout << "Enter the number of vertices (n): ";
    std::cin >> n;
    std::cout << "Enter the number of edges (m): ";
    std::cin >> m;

    // Step 2: Get the edges from the user
    std::cout << "Enter " << m << " edges (as pairs of vertices):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cout << "Edge " << i + 1 << ": ";
        std::cin >> u >> v;
        g.addEdge(u, v);  // Add the edge to the graph
    }

    // Step 3: Display the graph's adjacency list
    g.displayGraph();

    return 0;
}
