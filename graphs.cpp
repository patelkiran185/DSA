#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Graph
{
public:
    int a[5][5];
    int size;
    Graph(int sizr)
    {
        // size = sizr; 
        this->size = sizr;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                a[i][j] = 0;
            }
        }
    }
    void insertEdge(Graph *g, int u, int v)
    {
        g->a[u][v] = 1;
        g->a[v][u] = 1;
    }
    
    void printGraph(Graph *g)
    {
        for (int i = 0; i < g->size; i++)
        {
            for (int j = 0; j < g->size; j++)
            {
                cout << g->a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

    int main()
    {
        Graph *g = new Graph(5);
        g->insertEdge(g, 0, 1);
        g->insertEdge(g, 0, 3);
        g->insertEdge(g, 0, 2);
        g->insertEdge(g, 2, 3);
        g->insertEdge(g, 2, 4);
        g->printGraph(g);
        vector<int> an =g.getAdjacentNode(2); 
        for(int i=0;i<an.size();i++)
        {
            cout<<an[i]<<" ";
        }   
        return 0;
    }