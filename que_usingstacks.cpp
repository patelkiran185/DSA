//using stack data struture to implement queque
// Create queque using stack



// dequeue is expensive
// -> enqueue is simply pushing the data
// ->dequeue 1. if s1 and s2 both are empty return
//           2. if s2 is empty , push the elements of s1 into s2, push into s2, pop s1
//           3. then pop from s2


// enqueue is expensive
// ->enqueue 1. if s1 is empty, move from s1 to s2
//           2. new data is then pushed to s1.
//           3. if s2 is not empty, push data in s1 and pop s2
// ->dequeue s1 is empty then exit, if not simply pop 




#include<iostream>
#include<cstdlib> // Add missing include statement
using namespace std;
class Node
{
public:
    int data;
    Node *link;
    Node(int n) // Constructor
    {
        this->data = n;
        this->link = NULL;
    }
};
class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        if (!temp)
        {
            cout << "\nStack Overflow";
            exit(1);
        }

  
        temp->data = data;

        temp->link = top;

        top = temp;
    }

 
    bool isEmpty()
    {
       
        return top == NULL;
    }

 
    int peek()
    {
      
        if (!isEmpty())
            return top->data;
        else
            exit(1);
    }

    void pop()
    {
        Node *temp;

    
        if (top == NULL)
        {
            cout << "\nStack Underflow" << endl;
            exit(1);
        }
        else
        {

            temp = top;
            top = top->link;
            free(temp);
        }
    }
    void display()
    {
        Node *temp;
        if (top == NULL)
        {
            cout << "\nStack Underflow";
            exit(1);
        }
        else
        {
            temp = top;
            while (temp != NULL)
            {
                cout << temp->data;
                temp = temp->link;
                if (temp != NULL)
                    cout << " -> ";
            }
        }
    }
};
// class Queue{
//     Stack s1,s2;
//     public:
//     void enqueue(int data){
//         s1.push(data);
//     }
//     int dequeue(){
//         if(s1.isEmpty() && s2.isEmpty()){
//             cout<<"Queue is empty"<<endl;
//             exit(1);
//         }
//         if(s2.isEmpty()){
//             while(!s1.isEmpty()){
//                 s2.push(s1.peek()); //
//                 s1.pop(); 
//             }
//         }
//         int x=s2.peek();
//         s2.pop();
//         return x;
//     }
// };
// int main(){
//     Queue q1; // int n / Queue q1
//     q1.enqueue(1); 
//     q1.enqueue(2);
//     q1.enqueue(3);
//     cout<<q1.dequeue()<<endl;
//     cout<<q1.dequeue()<<endl;
//     cout<<q1.dequeue()<<endl;
//     return 0;
// }
// this is when dequeque is expensive. both should be empty s1 is not empty. pop all elements of stack s1 and push into s2. pop from s2
// enqueque-simply push


// when enqueque is expensive, both should be empty, data to be pushed in s1 and then when adding new data, pop from stack s1 and push to s2, repeat thsi and then 
// empty 
class Queue{
    Stack s1,s2;
    public:
    void enqueue(int x){
        //move from s1 to s2
        while(!s1.isEmpty()){
            s2.push(s1.peek());
            s1.pop();
        }
        //push data into s1
        s1.push(x);
        //push everything back to s1
        while(!s2.isEmpty()){
            s1.push(s2.peek());
            s2.pop();
        }
    }
    int dequeue()
    {
        // s1 is empty
        if (s1.isEmpty()) {
            cout << "Q is Empty";
            exit(0);
        }

        int x = s1.peek();
        s1.pop();
        return x;
    }
};
int main(){
    Queue q1; // int n / Queue q1
    q1.enqueue(1); 
    q1.enqueue(2);
    q1.enqueue(3);
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    return 0;
}