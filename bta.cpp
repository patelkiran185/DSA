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
        for(int i=0;i<7;i++){
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

    return 0;
}
