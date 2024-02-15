#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node(int d){
        data = d;
        next = NULL;
    }
};
class Queue{
    public:
        Node*front = NULL;
        Node*rear = NULL;
        bool isEmpty(){
            return front == NULL && rear == NULL;;
        }
        
        void enqueue(int val){
            Node* newNode = new Node(val);
            if(isEmpty()){
                front = rear = newNode;
                return;
            }
            rear->next = newNode;
            rear = newNode;
        }
        void dequeue(){
            if(isEmpty()){
                cout<<"queue is empty, cant dequeue";
            }
            Node*temp = front;
            front = front->next;
            delete temp;
        }
        void display(){
            Node*temp = front;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};
int main(){
    Queue q;
    q.enqueue(11);
    q.enqueue(15);
    q.display();
    return 0;
}