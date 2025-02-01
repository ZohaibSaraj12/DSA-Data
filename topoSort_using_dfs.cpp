#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Graph {
public:
    // Adjacency list representation
    vector<vector<int>> adjList;

    // Function to add a directed edge between vertices u and v
    void addEdge(int u, int v) {
        // Ensure that the adjacency list has enough space to store the vertices
        if (adjList.size() <= u) {
            adjList.resize(u + 1);  // Resize only if needed (for higher indices)
        }
        if (adjList.size() <= v) {
            adjList.resize(v + 1);  // Resize only if needed (for higher indices)
        }

        // Add the directed edge from u to v
        adjList[u].push_back(v);
    }

    // Function to perform DFS and add vertices to the stack for topological sort
    void dfs(int vertex, vector<int>& visited, stack<int>& topoStack) {
        // Mark the current node as visited
        visited[vertex] = 1;
        int i = 0;
        cout << "\n" << "dfs ki shruat vertex bhi dekh lo  " << vertex << endl;
        
        // Visit all neighbors
        for (int neighbor : adjList[vertex]) {
            cout << "\ncontrol agia dfs k paas " << neighbor << " " << visited[i] << endl;
           
            i++;
            
            if (!visited[neighbor]) {
            	cout << "\nsuccessfully ham neighbour ko visit kar rahy hain aur recursion shrooh " << endl;
                dfs(neighbor, visited, topoStack);
                cout << "\nrecursion k baad wapsi neihbor bhi dkh lo inside condition" << neighbor << endl;
            }
            cout << "\nrecursion k baad wapsi neihbor bhi dkh lo " << neighbor << endl;
        }
        
        cout << "\n" << "stack mein " << vertex << " ko push kar rahy" << endl;
        // Push the current vertex to the stack (after visiting all its neighbors)
        topoStack.push(vertex);
        cout << "\n Dobara dfs mein ja rahy hain" << endl;
    }

    // Function to perform Topological Sort
    void topologicalSort(int vertices) {
        vector<int> visited(vertices, 0);
        stack<int> topoStack;

        // Call DFS for all vertices
        cout << "\ntopoSort ko control milgia" << endl;
        for (int i = 0; i < vertices; ++i) {
            if (!visited[i]) {
                dfs(i, visited, topoStack);
            }
            cout << "\n wapis mil gia control" << endl;
        }

        // Output the topological order (in reverse order of stack)
        cout << "Topological Sort: ";
        while (!topoStack.empty()) {
            cout << topoStack.top() + 1 << " ";  // Convert back to 1-based index
            topoStack.pop();
        }
        cout << endl;
    }

    // Function to display the graph's adjacency list
    void displayGraph() {
        for (int i = 0; i < adjList.size(); ++i) {
            cout << "Vertex " << i + 1 << " is connected to: ";
            for (int neighbor : adjList[i]) {
                cout << neighbor + 1 << " ";  // Convert to 1-based index for display
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    // Step 1: Get the number of vertices and edges
    int n, m;
    cout << "Enter the number of vertices (n): ";
    cin >> n;
    cout << "Enter the number of edges (m): ";
    cin >> m;

    // Step 2: Get the edges from the user
    cout << "Enter " << m << " directed edges (from -> to):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        
        cin >> u >> v;
        g.addEdge(u - 1, v - 1);  // Convert to 0-based indexing
    }
   
    
    // Step 3: Display the graph's adjacency list
    cout << "Graph's adjacency list:\n";
    g.displayGraph();

    // Step 4: Perform Topological Sort
    g.topologicalSort(n);

    return 0;
}
// 1 2 1 3 2 4 3 4 4 5 4 6 5 6