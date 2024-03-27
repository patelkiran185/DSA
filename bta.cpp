#include<iostream>
using namespace std;
#define N 1000
class BinartTreeArray{
    int a[N];
    int top=0;
    int root;
    public:
    BinartTreeArray(int r){
        a[0]=r;
        top++;
    }
    void setLeft(int rootIndex,int element){
        a[(rootIndex*2)+1]=element;
        top+=1;
    }
    void setRight(int rootIndex,int element){
        a[(rootIndex*2)+2]=element;
        top+=1;
    }
    int size(){
        return top;
    }
    int ParentIndex(int index){
        return ((index-1)/2);
    }
    void printTree(){
        for(int i=0;i<top;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    void InOrderDisplay(int r){
        if(r>=top){
            return;
        }
        InOrderDisplay(2*r+1);
        cout<<a[r]<<" ";
        InOrderDisplay(2*r+2);
    }
    void PreOrderDisplay(int r){
        if(r>=top){
            return;
        }
        cout<<a[r]<<" ";
        PreOrderDisplay(2*r+1);
        PreOrderDisplay(2*r+2);
    }
    void PostOrderDisplay(int r){
        if(r>=top){
            return;
        }
        PostOrderDisplay(2*r+1);
        PostOrderDisplay(2*r+2);
        cout<<a[r]<<" ";
    }
    void insertElement(int element){
        a[top]=element;
        top+=1;
    }
    void insertAtPosition(int element,int position){
        a[position]=element;
    }
    void deleteElement(int element){
        for(int i=0;i<top;i++){
            if(a[i]==element){
                for(int j=i;j<top-1;j++){
                    a[j]=a[j+1];
                }
                top-=1;
                break;
            }
        }
    }
    void deleteAtPos(int position){
        for(int i=position;i<top-1;i++){
            a[i]=a[i+1];
        }
        top-=1;
    }
    void diameterOfBinaryTree(int root){
        int leftHeight=0;
        int rightHeight=0;
        if(root>=top){
            return;
        }
        if(2*root+1<top){
            leftHeight=height(2*root+1);
        }
        if(2*root+2<top){
            rightHeight=height(2*root+2);
        }
        cout<<leftHeight+rightHeight+1;
    }
    int height(int root){
        if(root>=top){
            return 0;
        }
        int leftHeight=0;
        int rightHeight=0;
        if(2*root+1<top){
            leftHeight=height(2*root+1);
        }
        if(2*root+2<top){
            rightHeight=height(2*root+2);
        }
        return max(leftHeight,rightHeight)+1;
    }

};
int main (){
    BinartTreeArray* bta= new  BinartTreeArray(9);
    bta->setLeft(0,5);
    bta->setRight(0,6);
    bta->setLeft(1,3);
    bta->setRight(1,4);
    bta->setLeft(2,7);
    bta->setRight(2,8);
    bta->printTree();
    cout << "\nPreOrderDisplay: ";
    bta->PreOrderDisplay(0);
    cout << endl;

    cout << "PostOrderDisplay: ";
    bta->PostOrderDisplay(0);
    cout << endl;

    cout << "InOrderDisplay: ";
    bta->InOrderDisplay(0);
    cout << endl;
    cout<<"DiaMeter of Binary Tree:";
    bta->diameterOfBinaryTree(0);
    cout<<endl;

    return 0;
}
