// Implementing  a stack using singly linked list
#include <bits/stdc++.h>
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

// Driven Program
int main()
{
    // Creating a stack
    Stack s;

    // Push the elements of stack
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);

    // Display stack elements
    s.display();

    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;

    // Delete top elements of stack
    s.pop();
    s.pop();

    // Display stack elements
    s.display();

    // Print top element of stack
    cout << "\nTop element is " << s.peek() << endl;

    return 0;
}