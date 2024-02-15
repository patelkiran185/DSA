// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;
// class Graph {
//     int V; 
//     vector<vector<int>> adj; 
// public:
//     Graph(int V) {
//         this->V = V;
//         adj.resize(V);
//     }
//     void addEdge(int v, int w) {
//         adj[v].push_back(w);
//         adj[w].push_back(v);
//     }
//     void BFS(int s) {
//         vector<bool> visited(V, false); 
//         queue<int> q; 
//         visited[s] = true; 
//         q.push(s);
//         while (!q.empty()) {
//             int current = q.front();
//             cout << current << " ";
//             q.pop();
//             for (int i : adj[current]) {
//                 if (!visited[i]) {
//                     q.push(i);
//                     visited[i] = true;
//                 }
//             }
//         }
//     }
// };

// int main() {
//     Graph g(6); 
//     g.addEdge(0, 1);
//     g.addEdge(0, 2);
//     g.addEdge(1, 3);
//     g.addEdge(1, 4);
//     g.addEdge(2, 4);
//     g.addEdge(3, 4);
//     g.addEdge(3, 5);
//     g.addEdge(4, 5);
//     cout << "BFS Traversal starting from vertex 0: ";
//     g.BFS(0); 
//     return 0;
// }



#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
private:
    int numVertices;
    list<int> *adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList = new list<int>[numVertices];
    }

    // Function to add an edge between vertices v1 and v2
    void insertEdge(int v1, int v2) {
        if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1); // For undirected graph
        } else {
            cout << "Invalid vertices!" << endl;
        }
    }

    // Breadth-First Search traversal using a queue
    void BFS(int startNode) {
        // Initialize a queue for BFS traversal
        queue<int> bfsQueue;
        // Initialize a boolean array to keep track of visited nodes
        bool *visited = new bool[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            visited[i] = false;
        }

        // Enqueue the starting node
        bfsQueue.push(startNode);
        // Mark the starting node as visited
        visited[startNode] = true;

        // Perform BFS traversal
        while (!bfsQueue.empty()) {
            // Dequeue a node from the queue
            int currentNode = bfsQueue.front();
            bfsQueue.pop();

            // Print the current node
            cout << currentNode << " ";

            // Enqueue all unvisited adjacent nodes of the current node
            for (int adjNode : adjList[currentNode]) {
                if (!visited[adjNode]) {
                    bfsQueue.push(adjNode);
                    visited[adjNode] = true; // Mark the node as visited
                }
            }
        }

        // Deallocate memory for the visited array
        delete[] visited;
    }
};

int main() {
    Graph g(7);

    g.insertEdge(0, 1);
    g.insertEdge(0, 2);
    g.insertEdge(1, 3);
    g.insertEdge(1, 4);
    g.insertEdge(2, 5);
    g.insertEdge(2, 6);

    cout << "Breadth-First Search traversal starting from node 0:" << endl;
    g.BFS(0);

    return 0;
}
