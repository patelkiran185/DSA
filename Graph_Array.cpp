#include<iostream>
using namespace std;

const int MAX_VERTICES=10;
class Graph{
    private:
    int numVertices;
    int adjacentMatrix[MAX_VERTICES][MAX_VERTICES];
    public:
    Graph(int vertices){
        numVertices=vertices;
        for(int i=0;i<numVertices;++i){
            for(int j=0;j<numVertices;j++){
                adjacentMatrix[i][j]=0;
            }
        }
    }
    void addEdge(int u,int v){
        adjacentMatrix[u][v]=1;
        adjacentMatrix[v][u]=1;
    }
    void printMatrix(){
        cout<<"Adjacent Matrix: "<<endl;
        for(int i=0;i<numVertices;++i){
            for(int j=0;j<numVertices;++j){
                cout<<adjacentMatrix[i][j]<< " ";
            }
            cout<<endl;
        }
    }
};
int main(){
    Graph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.printMatrix();
    return 0;
}