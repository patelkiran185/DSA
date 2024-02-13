// Binary Search Tree implementation using linked list
#include<iostream>
#include<queue>
#include "TreeNode.cpp"
using namespace std;
class BST{

    public:
        BST(){

        }
        Node* insertToBST(Node*&,int);
        void takeInput(Node*&);
        bool searchInBST(Node*,int);
        void printBST(Node*);

};

Node* BST :: insertToBST(Node* &root ,int data){
    // Insertion in a BST is  of :- O(logn) Time complexity
    if(root==NULL){
        root = new Node(data);
        return root;
    }

    if(data < root->val){
        // Go to left
        root->left = insertToBST(root->left,data);
        
    }

    else{
        // Go to left
        root->right = insertToBST(root->right,data);
    }

    return root;

}
void BST :: takeInput(Node* &root){
    int data;
    cout << "\nEnter data : \n" ;
    cin >> data;

    while(data!=-1){
        root = insertToBST(root,data);
        cin >> data;
    }

    
}

bool BST :: searchInBST(Node* root,int val){

    while(root!=NULL){

        if(val == root->val) return true;
        if(val < root->val){
            // Go to left subtree
            root = root->left;
        }

        if(val > root->val){
            // Go to right sub tree and search
            root = root->right;
        }
    }

    return false;

}

void BST :: printBST(Node* root){


    if(root==nullptr) return ;

    // Level-Order means --> printing elements level wise 
    cout << "\nLevel Order traversal of given BST is : \n " ;
    queue<Node*> qu;
    qu.push(root);

    while(!qu.empty()){
        
        int queue_Size = qu.size();
        for(int i=0;i<queue_Size;i++){
            Node* Front = qu.front();
            qu.pop();

            if(Front->left) qu.push(Front->left);
            if(Front->right) qu.push(Front->right);
            cout << (Front->val) << " ";

        }
        cout << endl;

    }

    return ;

}

int main(){

    Node* root = NULL;
    BST bst;
    bst.takeInput(root);
    bst.printBST(root);

    
    int N;
    cout << "Enter number to be searched in BST : ";
    cin >> N;
    bool found = bst.searchInBST(root,N);
    if(found) cout << N << " Found\n";
    else cout << N << " Not found\n";
    

    return 0;
}
