
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;
};

class LinkedList{
    Node *first;
    public:
    LinkedList(int arr[],int size);
    void Display();
    void addFirst(int num);
    void addLast(int num);
    void insert(int num,int index);
    int Length();
    int Delete(int num);
    void Reverse();
};

LinkedList::LinkedList(int arr[],int size){
    Node *t,*last;
    first = new Node();
    first->data = arr[0];
    first->next = NULL;
    first->prev = NULL;
    last = first;

    for(int i = 1;i<size;i++){
        t = new Node();
        t->data = arr[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void LinkedList::Display(){
    Node *p = first;
    
    while (p)
    {
        cout<<p->data<<"->";
        p = p->next;
    }
    cout<<"NULL"<<endl;
}



int LinkedList::Length(){
    Node *p = first;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}


void LinkedList::insert(int num,int index){
    Node *p,*t;
    p = new Node();
    p->data = num;
    p->next = NULL;
    p->prev = NULL;
    if(index == 0){
        addFirst(num);
    }
    else if(index == Length()){
        addLast(num);
    }
    else{
        t = first;
        for(int i = 0;i<index-1;i++){
            t = t->next;
        }
        p->next = t->next;
        p->prev = t;
        t->next->prev = p;
        t->next = p;
    }
}


void LinkedList::Reverse(){
    Node *p = first;
    Node *temp;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p!=NULL && p->next == NULL){
            first = p;
        }
    }
}

void LinkedList::addFirst(int num){
    Node *p;
    p = new Node();
    p->data = num;
    p->next = first;
    p->prev = NULL;
    first->prev = p;
    first = p;
}

void LinkedList::addLast(int num){
    Node *p;
    p = new Node();
    p->data = num;
    p->next = NULL;
    Node *last = first;
    while (last->next)
    {
        last = last->next;
    }
    last->next = p;
    p->prev = last;
}

int LinkedList::Delete(int index){
    Node *p,*q;
    int x = -1;
    if(index == 0){
        p = first;
        first = first->next;
        x = p->data;
        delete p;
        if(first){
            first->prev = NULL;
        }
    }
    else{
        p = first;
        for(int i = 0;i<index;i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if(p->next){
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }
    return x;
}


int main() {
    int arr[] = {1,2,3,4,5};
    LinkedList l(arr,5);
    l.Display();
    l.Reverse();
    l.Display();
    l.addFirst(10);
    l.Display();
    l.Delete(1);
    l.Display();
    l.insert(100,1);
    l.Display();
    l.addLast(9);
    l.Display();
    return 0;
}
