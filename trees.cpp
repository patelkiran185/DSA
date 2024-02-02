// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int data){
//         this->data=data;
//         left=NULL;
//         right=NULL;
//     }
// };
// class BinaryTree{
//     public:
//     Node* root;
//     BinaryTree(){
//         root=NULL;
//     }
//     void insert(int data){
//         Node* newNode=new Node(data);
//         if(root==NULL){
//             root=newNode;
//             return;
//         }
//         Node* temp=root;
//         while(temp!=NULL){
//             if(data<temp->data){
//                 if(temp->left==NULL){
//                     temp->left=newNode;
//                     return;
//                 }
//                 temp=temp->left;
//             }
//             else{
//                 if(temp->right==NULL){
//                     temp->right=newNode;
//                     return;
//                 }
//                 temp=temp->right;
//             }
//         }
//     }
//     void inorder(Node* root){
//         if(root==NULL){
//             return;
//         }
//         inorder(root->left);
//         cout<<root->data<<" ";
//         inorder(root->right);
//     }
//     void preorder(Node* root){
//         if(root==NULL){
//             return;
//         }
//         cout<<root->data<<" ";
//         preorder(root->left);
//         preorder(root->right);
//     }
//     void postorder(Node* root){
//         if(root==NULL){
//             return;
//         }
//         postorder(root->left);
//         postorder(root->right);
//         cout<<root->data<<" ";
//     }
//     void inorder(){
//         inorder(root);
//     }
//     void preorder(){
//         preorder(root);
//     }
//     void postorder(){
//         postorder(root);
//     }
// };
// int main(){
//     BinaryTree tree;
//     tree.insert(10);
//     tree.insert(5);
//     tree.insert(15);
//     tree.insert(3);
//     tree.insert(7);
//     tree.insert(12);
//     tree.insert(18);
//     tree.inorder();
//     cout<<endl;
//     tree.preorder();
//     cout<<endl;
//     tree.postorder();
//     cout<<endl;
//     return 0;
// }
