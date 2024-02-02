#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    int priority;
    Node *next;
    Node(int val,int prior){
        data=val;
        priority=prior;
        next=NULL;
    }
};
class PriorityQueue{
    Node *front;
    Node *rear;
    int size;
    public:
    PriorityQueue(){
        front=NULL;
        rear=NULL;
        size=0;
    }
    void insert(int,int);
    int poll();
    bool isEmpty();
    int getSize(){
        return size;
    }
};
bool PriorityQueue :: isEmpty(){
    return(!front || !rear);
}
void PriorityQueue :: insert(int val,int prior){
    Node *newNode=new Node(val,prior);
    if(isEmpty()){
        front=newNode;
        rear=newNode;
        size++;
        return;
    }
    if(prior<front->priority){
        newNode->next=front;
        front=newNode;
        size++;
        return;
    }
    if(prior>rear->priority){
        rear->next=newNode;
        rear=newNode;
        size++;
        return;
    }
    Node *temp=front;
    while(temp->next!=NULL && temp->next->priority<prior){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
    size++;
}
int PriorityQueue :: poll(){
    if(!isEmpty()){
        int first = front->data;
        front = front->next;
        size--;
        return first;

    }
    return -1;
}


void display(PriorityQueue pq){
    while(!pq.isEmpty()){
        cout << pq.poll() << " " ;
    }
    cout << endl ;
}

int main(){

    PriorityQueue pq;
    for(int i=1;i<=5;i++){
        int data,prior;
        cout << "Enter data and priority : ";
        cin >> data >> prior;
        pq.insert(data,prior);
    }
    display(pq);
    cout <<"\nFront element is : " <<pq.poll() << endl;
    display(pq);
    cout <<"Queue size is : "<< pq.getSize() << endl;

    return 0;
}