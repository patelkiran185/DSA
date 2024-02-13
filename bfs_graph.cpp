#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Graph {
    int V; 
    vector<vector<int>> adj; 
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    void BFS(int s) {
        vector<bool> visited(V, false); 
        queue<int> q; 
        visited[s] = true; 
        q.push(s);
        while (!q.empty()) {
            int current = q.front();
            cout << current << " ";
            q.pop();
            for (int i : adj[current]) {
                if (!visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
};

int main() {
    Graph g(6); 
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    cout << "BFS Traversal starting from vertex 0: ";
    g.BFS(0); 
    return 0;
}


