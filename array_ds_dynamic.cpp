// #include <iostream>
// using namespace std;
// class Array{
//     //state 
//     int capacity;
//     int size;
//     // string datatype;
//     int *a;
//     public:
//     //constructor
//     Array(int capacity,int size,int b[]){
//         this->capacity=capacity;
//         this->size=size;
//         this->a=new int[capacity]; //a=new....
//         for (int i =0;i<size;i++){
//             *(a+i)=b[i];
//         }
//     }

//     void printArray(){
//         for (int i=0;i<size;i++){
//             cout<< *(a+i)<<" ";
//         }
//         cout<<""<<endl;
//     }

//     void insert(int element){
//         if(size==capacity){
//             cout<<"Can't insert full"<<endl;
//             return;
//         }
//         else{
//             cout<<"inserted"<<endl;
//             a[size]=element;
//             size+=1;
//         }
//     }


// //Array{
// //     size=10;
// //     capacity=10;
// //     a = new int[capacity]
// // }
// // void insert(int index,int element){
// //     if(size==capacity) cout<< "Capacity full";
// //     else{
// //         for(int i;i>size;i--){
// //             a[i-1]=
// //         }
// //     }
// // }

// // };
// // int main(){
// //     int s[]={10,5,4,9,6};
// //     Array a(8,5,s);
// //     a.printArray();
// //     a.insert(50);
// //     a.printArray();

// //     return 0;
// // }



// this pointer
// #include <iostream>
// using namespace std;    
// class Student {
// public:
//     int id;
//     string name;
//     float percent;
//     int rank;

//     Student(int id, string name, float percent,int rank) {
//         this->id = id;
//         this->name = name;
//         this->percent = percent; 
//         this->rank=rank;
//     }

//     void display() {
//         cout << id << " " << name << " " << percent << " " << rank<<endl;
//     }

// };
// int main(){
//     Student s1=Student(1,"A",90,5);
//     s1.display();
//     Student s2=Student(2,"B",80,9);
//     s2.display();

//     return 0;
// }





// #include <iostream>
// using namespace std;
// void fun(int n){
//     if(n>0){
//         fun(n-1);
//         cout<<n<<" ";

//         // fun(n-1);
//     }
// }
// int main(){
//     int x=3;
//     fun(x);
//     return 0;
// }




#include<iostream>
using namespace std;
// int funA(int x);
// int funB(int x);
// int funA(int x){
//     if(x>0){
//         cout<<x<<endl;
//         funB(x-1);
//     }
// }
// int funB(int x){
//     if(x>0){
//         cout<<x<<endl;
//         funA(x-1);
//     }
// }
// int main(){
//     int x = 10;
//     funA(x);
// }
int main(){
int sparsematrix[4][5]={
    {0,0,3,0,4},
    {0,0,5,7,0},
    {0,0,0,0,0},
    {0,2,6,0,0}
};

int size;
for(int i=0;i<4;i++){
    for (int j=0;j<5;j++){
        if(sparsematrix[i][j]!=0){
            size+=1;
        }
    }
}
int k=0;
int compactmatrix[3][size];
for(int i=0;i<4;i++){
    for (int j=0;j<5;j++){
        if(sparsematrix[i][j]!=0){
            compactmatrix[0][k]=i;
            compactmatrix[1][k]=j;
            compactmatrix[2][k]=sparsematrix[i][j];
            k+=1;
        }
    }
}

for (int i=0;i<3;i++){
    for (int j=0;j<size;j++){
        cout<<compactmatrix[i][j]<<" ";
    }
    cout<<endl;
}   
return 0;
}