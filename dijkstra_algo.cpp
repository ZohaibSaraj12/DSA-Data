#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<pair<int, int>>> adjList;  // adjacency list: node, weight

    Graph(int v) {
        vertices = v;
        adjList.resize(v);
    }

    // Add an edge to the graph
    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // If the graph is undirected
    }

    // Dijkstra's Algorithm using a set
    vector<int> dijkstra(int source) {
        // Distance array to store the shortest distance to each vertex
        vector<int> dist(vertices, INT_MAX);
        dist[source] = 0;

        // Set to store the nodes along with their current distance
        set<pair<int, int>> s;
        s.insert({0, source});  // {distance, node}

        while (!s.empty()) {
            // Get the node with the smallest distance
            auto current = *s.begin();
            int u = current.second;
            int d = current.first;
            s.erase(s.begin());  // Remove the node from the set

            // Explore the neighbors
            for (auto neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // If a shorter path is found
                if (d + weight < dist[v]) {
                    // Remove the old entry for v if it exists
                    if (dist[v] != INT_MAX) {
                        s.erase(s.find({dist[v], v}));
                    }
                    // Update the shortest distance and insert into the set
                    dist[v] = d + weight;
                    s.insert({dist[v], v});
                }
            }
        }

        return dist;
    }
};

int main() {
    Graph g(9);

    // Add edges to the graph (u, v, weight)
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 8, 2);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int source = 0;  // Starting node
    vector<int> distances = g.dijkstra(source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < distances.size(); i++) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
