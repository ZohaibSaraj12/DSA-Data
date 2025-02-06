#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Step 1: Initialize distance vector
    vector<int> distance(n + 1, INT_MAX); // Initialize all distances to a large value
    distance[src] = 0; // Distance to source is 0

    // Step 2: Relax all edges (n-1) times
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Step 3: Check for negative weight cycles
    bool flag = false;
    for (int j = 0; j < m; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int weight = edges[j][2];

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            flag = true; // Negative cycle detected
            break;
        }
    }

    // Step 4: Return the result
    if (flag) {
        return -1; // Negative cycle found
    } else {
        return (distance[dest] == INT_MAX) ? -1 : distance[dest]; // Return -1 if no path to dest
    }
}

int main() {
    // Example input
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(3));

    cout << "Enter the edges (u, v, weight):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src, dest;
    cout << "Enter the source and destination nodes: ";
    cin >> src >> dest;

    // Call Bellman-Ford algorithm
    int result = bellmanFord(n, m, src, dest, edges);

    if (result == -1) {
        cout << "There is no path from node " << src << " to node " << dest << " or there is a negative weight cycle." << endl;
    } else {
        cout << "The shortest path from node " << src << " to node " << dest << " is: " << result << endl;
    }

    return 0;
}
