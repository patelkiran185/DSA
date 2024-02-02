// #include<iostream>
// using namespace std;

// //size of queque
// //add / enqueue rear
// //remove / dequeue front

// class QNode{
//     public:
//         int data;
//         QNode *next;
        
//         QNode(int d){
//             data = d;
//             next = NULL;
//         }

// };
// class Queque{
//     public:
//         QNode *front;
//         QNode *rear;
//         int size;
//         Queque(){
//             front = NULL;
//             rear = NULL;
//             size=0;
//         }
//         void enQueue(int x);
//         void deQueue();
//         void displayQueue(QNode *front);
//     //     bool isempty();

//     // private:
//     // bool isempty(){
//     //     if(front == NULL){
//     //         return true;
//     //     }
//     //     else{
//     //         return false;
//     //     }
    
//     // }
// };

// //is size==limited number of ellements
// void Queque::enQueue(int x){
//     QNode *temp = new QNode(x);
//     temp->data=x;
//     temp->next = NULL;
//     if (size==10){
//         cout<<"Queue is full"<<endl;
//         return;
//     }
//     if(front == NULL && rear == NULL){
//         front = rear = temp;
//     }
//     else{
//         rear->next = temp;
//         rear = temp;
        
//     }
//     size++;
    
// }

// void Queque::deQueue(){
//     QNode *temp = front;
//     if (size==10){
//         cout<<"Queue is full"<<endl;
//         return;
//     }
//     if(front == NULL){
//         cout<<"Queue is empty"<<endl;
//     }
//     else if(front == rear){
//         front = rear = NULL;
//         delete temp;
//     }
//     else{
//         front = front->next;
//     }
//     delete temp;
//     size--;
//     }

// void displayQueue( QNode *front){
//     QNode *temp = front;
//     if(front == NULL){
//         cout<<"Queue is empty"<<endl;
//     }
//     else{
//         while(temp != NULL){
//             cout<<temp->data<<" ";
//             temp = temp->next;
//         }
//         cout<<endl;
//     }
// }


// int main(){
//     Queque q;
//     // q.isempty();
//     q.enQueue(10);
//     q.enQueue(20);
//     q.enQueue(30);
//     q.enQueue(40);
//     q.enQueue(50);
//     q.enQueue(60);
//     q.deQueue();
//     q.displayQueue(q.front);
//     // q.isempty();
//     return 0;
// }





























// // int main(){
//     // QNode *front = NULL;
//     // QNode *rear = NULL;
//     // QNode *temp = NULL;
//     // int choice;
//     // while(1){
//     //     cout<<"1. Enqueue"<<endl;
//     //     cout<<"2. Dequeue"<<endl;
//     //     cout<<"3. Display"<<endl;
//     //     cout<<"4. Exit"<<endl;
//     //     cout<<"Enter your choice: ";
//     //     cin>>choice;
//     //     switch(choice){
//     //         case 1:
//     //             temp = new QNode();
//     //             cout<<"Enter the data: ";
//     //             cin>>temp->data;
//     //             temp->next = NULL;
//     //             if(front == NULL && rear == NULL){
//     //                 front = rear = temp;
//     //             }
//     //             else{
//     //                 rear->next = temp;
//     //                 rear = temp;
//     //             }
//     //             break;
//     //         case 2:
//     //             temp = front;
//     //             if(front == NULL){
//     //                 cout<<"Queue is empty"<<endl;
//     //             }
//     //             else if(front == rear){
//     //                 front = rear = NULL;
//     //                 delete temp;
//     //             }
//     //             else{
//     //                 front = front->next;
//     //                 delete temp;
//     //             }
//     //             break;
//     //         case 3:
//     //             temp = front;
//     //             if(front == NULL){
//     //                 cout<<"Queue is empty"<<endl;
//     //             }
//     //             else{
//     //                 while(temp != NULL){
//     //                     cout<<temp->data<<" ";
//     //                     temp = temp->next;
//     //                 }
//     //                 cout<<endl;
//     //             }
//     //             break;
//     //         case 4:
//     //             exit(0);
//     //         default:
//     //             cout<<"Invalid choice"<<endl;
//     //     }
//     // }
// //     return 0;
// // }




















