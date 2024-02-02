#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        next=prev=nullptr;
    }
};

class DoubleLL{
    public:
    Node* head;
    DoubleLL(){
        head=nullptr;
    }
    int len();
 
    void insert(int val);
    void insertAtHead(int val,int pos);
    void insertAtTail(int val);
    void insertAtPos(int val,int pos);
    void deleteAtHead();
    void deleteAtTail();
    void deleteAtPos(int pos);
    void display();

};
int DoubleLL :: len(){
    Node* temp=head;
    int count=0;
    while(temp!=nullptr){
        count++;
        temp=temp->next;
    }
    return count;
}


void  DoubleLL :: insert(int val){
    Node* newNode=new Node(val);
    if(head==nullptr){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}
void  DoubleLL :: insertAtHead(int val,int pos){
    Node* newNode=new Node(val);
    if(head==nullptr){
        head=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
void  DoubleLL :: insertAtTail(int val){
    Node* newNode=new Node(val);
    if(head==nullptr){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
}
void  DoubleLL :: insertAtPos(int val,int pos){
    Node* newNode=new Node(val);
    if(head==nullptr){
        head=newNode;
        return;
    }
    Node* temp=head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}
void  DoubleLL :: deleteAtHead(){
    if(head==nullptr){
        return;
    }
    Node* temp=head;
    head=head->next;
    head->prev=nullptr;
    delete temp;
}
void  DoubleLL :: deleteAtTail(){
    if(head==nullptr){
        return;
    }
    Node* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->prev->next=nullptr;
    delete temp;
}
void  DoubleLL :: deleteAtPos(int pos){
    if(head==nullptr){
        return;
    }
    Node* temp=head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    Node* todelete=temp->next;
    temp->next=todelete->next;
    todelete->next->prev=temp;
    delete todelete;
}
void DoubleLL :: display(){
    Node* temp=head;
    cout<<"NULL";
    while(temp!=nullptr){

        cout<<"<-"<<temp->val<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(){
    DoubleLL dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.insert(4);
    dll.insert(5);
    cout<<"Length of the list is: "<<dll.len()<<"\n";
    cout<<"double linked list is:"<<endl;
    dll.display();
    cout<<"Inserting 10 at head:  "<<endl;
    dll.insertAtHead(10,0);
    dll.display();
    cout<<"Inserting 6 at tail:  "<<endl;
    dll.insertAtTail(6);
    dll.display();
    cout<<"Inserting 10 at position 3:  "<<endl;
    dll.insertAtPos(10,3);
    dll.display();
    cout<<"Deleting at head:  "<<endl;
    dll.deleteAtHead();
    dll.display();
    cout<<"Deleting at tail:  "<<endl;
    dll.deleteAtTail();
    dll.display();
    cout<<"Deleting at position 2:  "<<endl;
    dll.deleteAtPos(2);
    dll.display();
    return 0;
}
