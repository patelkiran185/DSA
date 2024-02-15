#include<iostream>
using namespace std;

#define SIZE 5

class Stack{
    public:
    int top = -1;
    int arr[SIZE];
    
    void push(int d){
        if(top==SIZE){
            cout<<"stack overflow"<<endl;
        }
        top++;
        arr[top]=d;
    }
    int pop(){
        if(top==-1){
            cout<<"stack underflow";
            return -1;
        }
        top--;
       int p= arr[top];
       return p;
    }
    void display(){
        if(top==-1){
            cout<<"empty stack"<<endl;
        }
        for(int i=top;i>=0;--i){
            cout<<arr[i];
        }
        cout<<endl;
    }
    int peek(int pos){
        return arr[pos];
    }
    void addAtPos(int val, int pos){
        arr[pos]=val;
        cout<<"val changed at loc"<<pos;
    }
    int count(){
        return top+1;
    }
};
int main(){
    Stack s1;
    int option, value, position;
    do {
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Count" << endl;
        cout << "5. Change" << endl;
        cout << "6. Peek" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter an item to push in the stack: ";
                cin >> value;
                s1.push(value);
                break;
            case 2:
                cout << "Popped Element: " << s1.pop() << endl;
                break;
            case 3:
                s1.display();
                break;
            case 4:
                cout << "Number of elements in the Stack are: " << s1.count() << endl;
                break;
            case 5:
                cout << "Enter position the item to be changed: ";
                cin >> position;
                cout << "Enter a new item: ";
                cin >> value;
                s1.addAtPos(position, value);
                break;
            case 6:
                cout << "Enter position of item you want to peek: ";
                cin >> position;
                cout << "Value at position is: " << s1.peek(position) << endl;
                break;
            case 0:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Enter correct option number" << endl;
        }

    } while (option != 0);

    return 0;
}