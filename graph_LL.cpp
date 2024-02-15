//adjacency ll adjlist

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        this->data=val;
        next=NULL;
    }

};
class LL{
    public:
    Node*head=NULL;
    void addNode(int val){
        Node*nn=new Node(val);
        nn->next=head;
        head=nn;
    }

};
class Graph{
    private:
    int vertex;
    LL*adjList;
    public:
    Graph(int v) : vertex(v),adjList(new LL[v]){}
    void addEdge(int src,int dest){
        adjList[src].addNode(dest);
        adjList[dest].addNode(src);
    }
    void printGraph(){
        for(int i=0;i<vertex;i++){
            Node *curr=adjList[i].head;
            while(curr!=NULL){
                cout<<curr->data<<" "<<endl;;
                curr=curr->next;
            }
        }
    }
};
int main(){
    Graph gg(4);
    gg.addEdge(0,4);
    gg.addEdge(1,2);
    gg.addEdge(3,1);
    gg.printGraph();
    return 0;
}

