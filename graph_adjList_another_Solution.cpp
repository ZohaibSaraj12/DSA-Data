#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Graph {
    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, int dir)
    {
        adj[u].push_back(v);
        if (dir == 0) 
        {
        adj[v].push_back(u);
        }
    }
    void printList()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (int j : i.second)
            {
                cout << j << ",";
            }
            cout << endl;

        }
        cout << endl;
    }
};
int main()
{
    int n, m;
    Graph g;
    cout << "Enter Number of Vertices or Nodes: " << endl;
    cin >> n;
    cout << "Enter Number of Edges: " << endl;
    cin >> m;
    
    int u, v;
    for (int i = 0; i < m; i++)
    {
        
        cin >> u >> v;
        g.addEdge(u, v, 0);

    }
    g.printList();
}