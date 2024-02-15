
// #include<iostream>
// #include<stack>
// using namespace std;

// stack<int> s1,s2;

// void dequeue(){
//     if(!s1.empty() && s2.empty()){
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         s2.pop();
//         while(!s2.empty()){
//             s1.push(s2.top());
//             s2.pop();
//         }
//     }
//     else{
//         cout<<"queue is empty ";
//     }
// }
// void enqueue(int val){
//     s1.push(val);
// }
// void display(){
//     if(!s1.empty() && s2.empty()){
//         while(!s1.empty()){
//             s2.push(s1.top());
//             s1.pop();
//         }
//         while(!s2.empty()){
//             cout<<s2.top()<<" ";
//             s1.push(s2.top());
//             s2.pop();
//         }
//         cout<<endl;
//     }
//     else{
//         cout<<"Queue is not empty";
//     }
// }

// int main(){
//     enqueue(20);
//     enqueue(30);
//     enqueue(40);
//     display();
//     dequeue();
//     display();
//     return 0;
// }


#include<iostream>
#include<stack>
using namespace std;
stack<int> s1,s2;
void dequeue(){
    if(!s1.empty() && s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    else{
        cout<<"Queue is empty";
    }
}
void enqueue(int val){
    s1.push(val);
}
void display(){
    if(!s1.empty() && s2.empty()){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        while(!s2.empty()){
            cout<<s2.top()<<" ";
            s1.push(s2.top());
            s2.pop();
        }
        cout<<endl;

    }
    else{
        cout<<"Queue is empty";
    }
}
int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    display();
    dequeue();
    display();
    dequeue();
    display();
    enqueue(500);
    display();
    return 0;
}