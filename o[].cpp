
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class CircularLinkedList
{
public:
    Node *last = NULL;
    void create(int d)
    {
        Node *temp = new Node(d);
        if (last == NULL)
        {
            last = temp;
            last->next = last;
        }
        else
        {
            temp->next = last->next;
            last->next = temp;
            last = temp;
        }
    }
    void prepend(int d)
    {
        Node *temp = new Node(d);
        if (last == NULL)
        {
            last = temp;
            last->next = last;
        }
        else
        {
            temp->next = last->next;
            last->next = temp;
        }
    }
    void addAfter(int val, int afterelement)
    {
        if (last == NULL)
            cout << "List is empty" << endl;
        else
        {
            Node *p;
            p = last->next;
            do
            {
                if (p->data == afterelement)
                {
                    Node *temp = new Node(val);
                    temp->next = p->next;
                    p->next = temp;
                    if (p == last)
                        last = temp;
                    return;
                }
                p = p->next;
            } while (p != last->next);
            cout << endl
                 << afterelement << " Not present in the list" << endl;
            return;
        }
    }
    void display()
    {
        Node *temp = last;
        if (last == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        temp = last->next;
        cout << "Elements in the list ...";
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
    void count(){
        Node *temp = last;
        if (last == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        temp = last->next;
        int count = 0;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != last->next);
        cout << "Number of elements in the list: " << count << endl;
    }
    void deleteNode(int value)
    {
        if (last == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *current = last->next;
        Node *previous = last;
        do
        {
            if (current->data == value)
            {
                previous->next = current->next;
                delete current;
                cout << "Node with value " << value << " deleted." << endl;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != last->next);
        cout << "Node with value " << value << " not found." << endl;
    }
};
int main()
{
    CircularLinkedList cl;
    cl.create(10);
    cl.create(20);
    cl.create(30);
    cl.create(40);
    cl.create(50);
    cl.display();
    cl.prepend(5);
    cl.display();
    cl.addAfter(25, 20);
    cl.display();
    cl.deleteNode(25);
    cl.display();
    cl.count();
    return 0;
}

