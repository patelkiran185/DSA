#include <iostream>
#include <list>
#include <stack>
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
    void insertEdge(int v1, int v2) {
        if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
            adjList[v1].push_back(v2);
            adjList[v2].push_back(v1); 
        } else {
            cout << "Invalid vertices!" << endl;
        }
    }
    void DFS(int startNode) {
    
        stack<int> dfsStack;
        dfsStack.push(startNode);
        while (!dfsStack.empty()) {
            int currentNode = dfsStack.top();
            dfsStack.pop();
            if (adjList[currentNode].front() != -1) {
                cout << currentNode << " ";
                adjList[currentNode].push_front(-1);
                for (int adjNode : adjList[currentNode]) {
                    if (adjNode != -1) {
                        dfsStack.push(adjNode);
                    }
                }
            }
        }
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

    cout << "Depth-First Search traversal starting from node 0:";
    g.DFS(0);
    cout<<endl;
    return 0;
}


