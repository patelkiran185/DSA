#include <iostream>
using namespace std;
class Node
{
public:
    int data; // int val
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
void inserAtHead(Node *&head, int data)
{
    Node *new_node = new Node(data);
    new_node->next = head;
    head = new_node;
} // O(1)
void insertAtTail(Node *&head, int data)
{
    Node *new_node_at_end = new Node(data);
    if (head == nullptr)
    {
        head = new_node_at_end;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node_at_end;
} // O(n)
// void insertAtPos(Node *&head, int data, int pos)
// {
//     if (pos == 0)
//     {
//         inserAtHead(head, data);
//         return;
//     }
//     Node *node_at_pos = new Node(data);
//     Node *temp = head;

//     int curr_pos = 0;
//     while (curr_pos != pos - 1)
//     {
//         temp = temp->next;
//         curr_pos++;
//     }

//     node_at_pos->next = temp->next;
//     temp->next = node_at_pos;
// } // O(pos) worst case O(n)


void insertAtPos(Node *&head, int data, int pos)
{


    if (pos == 0)
    {
        inserAtHead(head, data);
        return;
    }

    if (head == nullptr)
    {
        cout << "List is empty, cannot insert at position " << pos << endl;
        return;
    }

    Node *node_at_pos = new Node(data);
    Node *temp = head;

    int curr_pos = 0;
    while (temp != nullptr && curr_pos < pos - 1)
    {
        temp = temp->next;
        curr_pos++;
    }

    if (temp != nullptr)
    {
        node_at_pos->next = temp->next;
        temp->next = node_at_pos;
    }
    else
    {
       
        delete node_at_pos; // Cleanup the allocated memory
    }
}

void UpdateAtPos(Node *&head, int k, int data)
{
    Node *temp = head;
    int curr_pos = 0;
    while (temp != nullptr && curr_pos != k)
    {
        temp = temp->next;
        curr_pos++;
    }
    if (temp != nullptr)
    {
        temp->data = data; // update the data of kth node
    }
    else
    {
        cout << "position" << k << "not found" << endl;
    }

    // tempwillbe pointing to kth node
}


void deleteAtHead(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}
void deleteAtEnd(Node *&head){
    if (head==nullptr) return;
    else if(head->next==nullptr){
        delete(head);
        head=nullptr;
    }
    else{
        Node* temp=head;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        delete(temp->next);
        temp->next=nullptr;
    }

}
void display(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = nullptr;
    inserAtHead(head, 1);
    display(head);
    inserAtHead(head, 2);
    display(head);
    // UpdateAtPos(head,,8);
    // display(head);
    inserAtHead(head, 3);
    display(head);
    inserAtHead(head, 4);
    display(head);
    inserAtHead(head, 5);
    display(head);
    inserAtHead(head, 6);
    display(head);
    UpdateAtPos(head, 2, 80);
    display(head);
    inserAtHead(head, 7);
    display(head);
    
    insertAtTail(head, 10);
    display(head);


    insertAtPos(head,30,3);
    display(head);
    deleteAtHead(head);
    display(head);
    cout<<"delete at end"<<endl;
    deleteAtEnd(head);
    display(head);
    // Node* n1=new Node(10);
    // cout<<n1->data<<endl;
    return 0;
}

// ostream& operator<<(ostream& os,Node* head){
//     while(head!=nullptr){
//         os<<head->data<<"->";
//         head=head->next;
//     }
//     return os;
// }
// https://youtu.be/Kz_6lUoDO_Y?si=evjX9DokB0oNegDL