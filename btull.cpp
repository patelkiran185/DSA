#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node* right;

    Node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

class BinaryTree
{
    public:
    Node *root=NULL;

    void insert(int data)
    {
        Node *n=new Node(data);
        queue<Node*> q;
        if (root==NULL)
        {
            root=n;
        }
        else{
            q.push(root);
            while (!q.empty())
            {
                if (q.front()->left==NULL)
                {
                    q.front()->left=n;
                    break;
                }
                else if (q.front()->right==NULL)
                {
                    q.front()->right=n;
                    break;
                }
                else
                {
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                q.pop();
            }
        }    
    }

    void printLevelOrder()
    {
        //Level order
        queue<Node*> q;
        q.push(root);
        while (!q.empty())
        {
            cout<<q.front()->data<<" ";
            if (q.front()->left!=NULL)
                q.push(q.front()->left);
            if (q.front()->right!=NULL)
                q.push(q.front()->right);   
            q.pop();        
        }
        cout<<endl;
        
    }

    void PreOrder(Node* r)
    {
        //Root - Left - Right
        if (r==NULL)
            return;
        cout<<r->data<<" ";
        PreOrder(r->left);
        PreOrder(r->right);    
    }
    void InOrder(Node* r)
    {
        //Left - Root - Right
        if (r==NULL)
            return;
        InOrder(r->left);
        cout<<r->data<<" ";
        InOrder(r->right);
    }
    void PostOrder(Node *r)
    {
        //Left - Right - Root
        if (r==NULL)
            return;
        PostOrder(r->left);
        PostOrder(r->right);  
        cout<<r->data<<" ";
    }
};

int main()
{
    BinaryTree b;
    b.insert(100);
    b.insert(90);
    b.insert(80);
    b.insert(70);
    b.insert(60);
    b.insert(50);
    b.insert(40);
    cout<<"LEVEL ORDER: ";
    b.printLevelOrder();
    cout<<"PRE-ORDER: ";
    b.PreOrder(b.root);
    cout<<endl;
    cout<<"POST-ORDER:";
    b.PostOrder(b.root);
    cout<<endl;
    cout<<"IN ORDER: ";
    b.InOrder(b.root);
}