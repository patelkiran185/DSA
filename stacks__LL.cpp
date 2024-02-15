// // Implementing  a stack using singly linked list
// #include <bits/stdc++.h>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *link;
//     Node(int n) // Constructor
//     {
//         this->data = n;
//         this->link = NULL;
//     }
// };
// class Stack
// {
//     Node *top;

// public:
//     Stack()
//     {
//         top = NULL;
//     }

//     void push(int data)
//     {
//         Node *temp = new Node(data);
//         if (!temp)
//         {
//             cout << "\nStack Overflow";
//             exit(1);
//         }

//         temp->data = data;

//         temp->link = top;

//         top = temp;
//     }

//     bool isEmpty()
//     {

//         return top == NULL;
//     }

//     int peek()
//     {

//         if (!isEmpty())
//             return top->data;
//         else
//             exit(1);
//     }

//     void pop()
//     {
//         Node *temp;

//         if (top == NULL)
//         {
//             cout << "\nStack Underflow" << endl;
//             exit(1);
//         }
//         else
//         {

//             temp = top;
//             top = top->link;
//             free(temp);
//         }
//     }
//     void display()
//     {
//         Node *temp;
//         if (top == NULL)
//         {
//             cout << "\nStack Underflow";
//             exit(1);
//         }
//         else
//         {
//             temp = top;
//             while (temp != NULL)
//             {
//                 cout << temp->data;
//                 temp = temp->link;
//                 if (temp != NULL)
//                     cout << " -> ";
//             }
//         }
//     }
// };

// // Driven Program
// int main()
// {
//     // Creating a stack
//     Stack s;

//     // Push the elements of stack
//     s.push(11);
//     s.push(22);
//     s.push(33);
//     s.push(44);

//     // Display stack elements
//     s.display();

//     // Print top element of stack
//     cout << "\nTop element is " << s.peek() << endl;

//     // Delete top elements of stack
//     s.pop();
//     s.pop();

//     // Display stack elements
//     s.display();

//     // Print top element of stack
//     cout << "\nTop element is " << s.peek() << endl;

//     return 0;
// }


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
class Stack{
    public:
        Node*top = NULL;
        
        bool isEmpty(){
            return top==NULL;
        }
        void push(int val){
            Node*nn = new Node(val);
            nn->next = top;
            top = nn;
        }
        int pop(){
            if(isEmpty()){
                cout<<"empty";
            }
            int poppedValue = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            cout << poppedValue << " popped from the stack." << endl;
            return poppedValue;
        }
        void display(){
            if(isEmpty()){
                cout<<"empty";
            }
            Node*temp = top;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp -> next;
            }
            cout<<endl;
        }
        int count(){
            if(isEmpty()){
                cout<<"empty";
            }
            Node*temp = top;
            int c = 0;
            while(temp!=NULL){
                c++;
                temp = temp->next;
        }
        return c;
    }
};
int main(){
    Stack s;
    s.push(11);
    s.push(27);
    s.push(15);
    s.push(9);
    s.pop();
    s.display();
}