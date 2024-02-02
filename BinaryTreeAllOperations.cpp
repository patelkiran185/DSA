// #include<iostream> //header file input and output
// #include<queue> //for levelorder transfer
// #include "TreeNode.cpp" //node
// using namespace std;


// /*
// 1. Header file
// 2. making a class binarytree (
//     -> numberof nodes
//     -> public: binarytree constructor, 6 functions)
// 3. int binarytree :: getNoOfNodes(Node*root)
// 4. Node *BinaryTree :: buildtreee(Node* &root)
// 5. void functions of preOrder,inOrder and postorder
//                     (RoLR)    (LRoR)      (LRRo)
// 6. void levelorder
// 7. int main




// preOrder(RoLR)
// inOrder(LRoR)
// postOder(LRRo)
// */

// class BinaryTree{
//     int numberOfNodes;
//     public:
//         BinaryTree(){
//             numberOfNodes = 0;

//         }
//         Node* buildTree(Node*&);
//         void preOrder(Node*);
//         void inOrder(Node*);
//         void postOrder(Node*);
//         void levelOrder(Node*);
//         int getNoOfNodes(Node*);

// };

// int BinaryTree :: getNoOfNodes(Node*root){
//     return numberOfNodes;
// }

// Node* BinaryTree :: buildTree(Node* &root){

//     cout << "\nEnter the data : ";
//     int data;
//     cin >> data;
//     // Create a root node or initalise it
//     root = new Node(data);

//     if(data==-1) return NULL;

//     cout << "Enter data to be inserted to the left of " << data << " " ;
//     root->left = buildTree(root->left);
//     cout << "Enter data to be inserted to the right of " << data << " " ;
//     root->right = buildTree(root->right);
//     return root;
// }

// void BinaryTree :: preOrder(Node* root){

//     if(!root) return;
//     // Preorder=> (Root , Left , Right)
//     cout << root->val << " " ;
//     preOrder(root->left);
//     preOrder(root->right);
// }

// void BinaryTree :: inOrder(Node* root){
//     if(!root) return ;
//     // Inorder => (Left Root Right)
//     inOrder(root->left);
//     cout << root->val << " " ;
//     inOrder(root->right);
// }

// void BinaryTree :: postOrder(Node* root){
//     if(!root) return;

//     // PostOrderr => (Left , Right , Root)
//     postOrder(root->left);
//     postOrder(root->right);
//     cout << root->val << " " ;
//     numberOfNodes++;
// }

// void BinaryTree :: levelOrder(Node* root){

//     if(!root) return;
//     queue<Node*>qu;
//     qu.push(root);

//     while(!qu.empty()){
//         int queueSize = qu.size();

//         for(int i=0;i<queueSize;i++){
//             Node* Front = qu.front();
//             qu.pop();
//             if(Front->left) qu.push(Front->left);
//             if(Front->right) qu.push(Front->right);
//             cout << Front->val << " " ;
//         }
//         cout << endl;

//     }

// }

// int main(){

//     BinaryTree bt;
//     Node* root = NULL;
//     bt.buildTree(root);

//     cout << "\nPre-order traversal : " ;
//     bt.preOrder(root);

//     cout << "\nIn-order traversal : " ;
//     bt.inOrder(root);

//     cout << "\nPost-order traversal : " ;
//     bt.postOrder(root);

//     cout << "\n\nLevel order traversal : \n";
//     bt.levelOrder(root);

//     cout << "\nNumber of nodes in tree : " << bt.getNoOfNodes(root) << endl;

//     return 0;
// }

















#include<iostream>
#include<queue>
#include "TreeNode.cpp"
using namespace std;

class BinaryTree{
    int numberOfNodes;
    public:
    BinaryTree(){
        numberOfNodes=0;
    }  
    Node* buildTree(Node*&);
    void preOrder(Node*);
    void inOrder(Node*);
    void postOrder(Node*);
    void levelOrder(Node*);
    int getNoOfNodes(Node*);
};

int BinaryTree :: getNoOfNodes(Node*root){
    return numberOfNodes;
}
Node*BinaryTree :: buildTree(Node*&root){
    cout<<"\nEnter data: ";
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1) return NULL;

    cout<<"Enter the left of "<<data<<" ";
    root->left=buildTree(root->left);
    cout<<"Enter the right of "<<data<<" ";
    root->right=buildTree(root->right);
    return root;
}
void BinaryTree :: preOrder(Node*root){
    //RoLR
    if(!root) return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void BinaryTree ::  inOrder(Node*root){
    //LRoR
    if(!root) return;
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}
void BinaryTree ::  postOrder(Node*root){
    //LRRo
    if(!root) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->val<<" ";
    numberOfNodes++;
}

void BinaryTree :: levelOrder(Node*root){
    if(!root) return;

    queue<Node*>qu;
    qu.push(root);
    while(!qu.empty()){
        int queSize=qu.size();
        for(int i=0;i<queSize;i++){
            Node *Front =qu.front();
            qu.pop();
            if(Front->left) qu.push(Front->left);
            if(Front->right) qu.push(Front->right);
            cout<<Front->val<<" ";
        }
        cout<<endl;
    }
}
int main(){
    BinaryTree bt;
    Node*root=nullptr;
    bt.buildTree(root);
    cout<<"PreOrder\n";
    bt.preOrder(root);
    cout<<"InOrder\n";
    bt.inOrder(root);
    cout<<"PostOrder\n";
    bt.postOrder(root);
    return 0;
}
// 1 2 3 -1 -1 4 -1 -1 3 5 -1 -1 6 -1 -1


void BinaryTree :: levelOrder(Node*root){
    if(!root) return;
    queue<Node*>qu;
    qu.push(root);
    while(!qu.empty()){
        for(int i =0 ; i< qu.size();i++){
            Node * Front = qu.front();
            qu.pop();
            if(Front->left) qu.push(Front->left);
            if(Front->right) qu.push(Front->right);
            cout<<Front->val<<" ";
        }
        cout<<endl;
    }
}