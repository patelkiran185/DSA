#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the beginning of the linked list
    void insert(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }

    // Function to print the linked list in the specified format
    void display() {
        Node* temp = head;

        // Displaying the linked list in the format 1->2->3->NULL
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << "->NULL" << endl;

        // Displaying the reversed linked list in the format NULL->3->2->1
        temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << "->";
            }
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }
};

int main() {
    LinkedList list;

    // Inserting elements into the linked list
    list.insert(1);
    list.insert(2);
    list.insert(3);

    cout << "Original Linked List: ";
    list.display();

    // Reversing the linked list
    list.reverse();

    cout << "Reversed Linked List: ";
    list.display();

    return 0;
}
