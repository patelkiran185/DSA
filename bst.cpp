

// binary tree search
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;
    
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
    
Node*findMin(Node*root){
    Node*temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

Node*insert(Node*root, int key){
    Node*nn = new Node(key);
        if(root==NULL){
            return nn;
    }
    if(key<root->data){
        root->left = insert(root->left,key);
    }
    else if(key>root->data){
        root->right = insert(root->right,key);
    }
    return root;
}
    
Node*search(Node*root,int key){
    if(root->data==key){
        return root;
    }
    if(key<root->data){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
    
Node*deleteNode(Node*root,int key){
    if(root==NULL){
        return root;
    }
    if(key<root->data){
        root->left = deleteNode(root->left,key);
    }
    else if(key>root->data){
        root->right = deleteNode(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node*temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node*temp = root->left;
            delete root;
            return temp;
        }
        Node*temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}
    
void inorder(Node*root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main(){
    Node*root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 6);
    insert(root, 8);
    int key = 4;
    Node* result = search(root, key);
    if (result != NULL) {
        cout << "Node with key " << key << " found!" << endl;
    }
    else{
        cout << "Node with key " << key << " not found!" << endl;
    }
    
    cout<<"inorder: "<<endl;
    inorder(root);
    
    key = 3;
    root = deleteNode(root, key);
    cout << "Node with key " << key << " deleted!" << endl;
    
    inorder(root);
    return 0;
}





