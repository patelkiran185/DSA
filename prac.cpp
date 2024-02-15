// #include<iostream>
// using namespace std;

// // class Node{
// //     public:
// //     int val;
// //     Node *prev,*next;
// //     Node(int val){
// //         this->val=val;
// //         next=prev=nullptr;
// //     }
// // };
// // class DoubleLL{
// //     public:
// //     Node*head;
// //     DoubleLL(){
// //         head=nullptr;
// //     }
// //     int len();
// //     void insert(int val);
// //     void insertAtHead(int val,int pos);
// //     void insertAtEnd(int val);
// //     void insertAtPos(int val,int pos);
// //     void deleteAtHead();
// //     void deleteAtTail();
// //     void printReverse();
// //     void deleteAtPos(int pos);
// //     void display();
// // };
// // int DoubleLL :: len(){
// //     Node *temp=head;
// //     int c=0;
// //     while(temp->next != NULL){
// //         c++;
// //         temp=temp->next;
// //     }
// //     return c;
// // }

// // void  DoubleLL :: insert(int val){
// //     Node* newNode=new Node(val);
// //     if(head==nullptr){
// //         head=newNode;
// //         return;
// //     }
// //     Node* temp=head;
// //     while(temp->next!=nullptr){
// //         temp=temp->next;
// //     }
// //     temp->next=newNode;
// //     newNode->prev=temp;
// // }


// // void DoubleLL :: display(){
// //     Node* temp=head;
// //    cout<<"NULL<-";
// //     while(temp!=NULL){
// //         cout<<temp->val<<"->";
// //         temp=temp->next;
// //     }
// //     cout<<"NULL"<<endl;
// // }
// // void DoubleLL ::  printReverse(){
// //     Node *temp=head;
// //     while(temp->next != NULL){
// //         temp=temp->next;
// //     }
// //     cout<<"NULL";
// //     while(temp!= NULL){
// //         cout<<" <- "<<temp->val<<" -> ";
// //         temp=temp->prev;
// //     }
// //     cout<<"NULL"<<endl;
// // }
// // int main(){
// //     DoubleLL ll;
// //     ll.insert(10);
// //     ll.insert(20);
// //     ll.insert(30);
// //     ll.insert(40);
// //     ll.insert(50);
// //     cout<<"Length of DOUBLE LL: "<<ll.len()<<endl;
// //     ll.display();
// //     ll.printReverse();


// // }



// #include<iostream>
// #include<stack>
// using namespace std;


// int precedence(char c){
//     if( c == '^') return 3;
//     if ( c == '/' || c == '*') return 2;
//     if(c == '+' || c == '-') return 1;
//     else return -1;
// }
// char associativity(char c){
//     if (c == '^') {
//         return 'R';
//     }
//     return 'L';
// }
// string infixToPostfix(string s){
//     stack <char> st;
//     string result= "";
//     for(int i=0;i<s.size();i++){
//         char c = s[i];
//         if((c >= 'A' && c <= 'Z') || (c>='a' && c <= 'z')){
//             result +=c;
//         }
//         else if ( c == '('){
//             st.push(c);
//         }
//         else if ( c == ')'){
//             while(st.top() != '('){
//                 result+=st.top();
//                 st.pop();
//             }
//             st.pop();
//         }
//         else{
//             while(st.empty() && (precedence(c) < precedence(st.top)) || (precedence(c) == precedence(st.top() && associativity(c)=='L'))){
//                 result += st.top();
//                 result.pop();
//             }
//             st.push();
//         }
//     }
//     return result;
// }




// int main(){
//     string ii;
//     cout<<"Enter infix: ";
//     cin>>ii;
//     cout<<infixToPostfix(ii)<<endl;
//     return 0;
// }



// #include<iostream>
// #include<stack>
// using namespace std;
// bool isPalindrome(string s){
//     int length=s.size();
//     stack<char> st;
//     int mid=length/2;
//     for(int i=0;i<mid;i++){
//         st.push(s[i]);
//     }
//     int i = (length% 2 == 0) : mid ? mid+1;
//     while(i<length){
//         char ele =st.top();
//         st.pop();
//         if(ele != s[i]){
//             return false;
//         }
//         i++;
//     }
//     return true;
// }


// class Node{
//     public: 
//     int val;
//     Node* next;
//     Node(int data){
//         val=data;
//         next=NULL;
//     }
// };
// class Stack{
//     public:
//     Node*top=NULL;
//     bool isEmpty{
//         return top==NULL;
//     }
//     void push(int val){
//         Node * nn = new Node(val);
//         nn->next=top;
//         top=nn;
//     }
//     int pop(){
//         if(isEmpty()){
//             cout<<"Empty";
//             return;
//         }
//         int popped=top->data;
//         Node* temp=top;
//         top=top->next;
//         delete temp;
//         cout<<"Pop";
//         return popped;
//     }
//     void display(){
//         if(isEmpty()){
//             cout<<"Empty";
//             return;
//         }
//         Node* temp=top;
//         while(temp!=NULL){
//             cout<<temp->data<<" ";
//             temp=temp->next;
//         }
//         cout<<endl;
//     }

// }


#include<iostream>
using namespace std;

// void Merge(int arr[],int l,int mid, int r){
//     int n1=mid-1+l;
//     int n2=r-mid;
//     int  a[n1];
//     int b[n2];
//     for(int i=0;i<n1;i++){
//         a[i]=a[l+1];
//     }
//     for(int i=0;i<n2;i++){
//         b[i]=b[mid+1+i];
//     }
//     int i=0,j=0,k=l;
//     while(i<n1 && j<n2){
//         if(a[i]<b[j]){
//             a[k]=a[i];
//             i++;
//             k++;
//         }
//         else{
//             a[k]=b[j];
//             j++;
//             k++
//         }
//     }
//     while(i<n1){
//         a[k]=a[i];
//         i++;
//         k++;
//     }
//     while(j<n2){
//         a[k]=b[j];
//         j++;
//         k++;
//     }
// }
// int binarySearch(int arr[],int n,int key){
//     int e=0;
//     int s=n;
//    while(s<=e){
//     int mid=(s+e)/2;
//     if(arr[mid]==key){
//         return mid;
//     }
//     else if (arr[mid]>key){
//         e=mid-1;
//     }
//     else{
//         s=mid+1;
//     }
//    }
//    return -1;


// }
// int main(){
//     int arr[10];
//     for (int i=0;i<10;i++){
//         cin>>arr[i];
//     }
//     return 0;
// }


const int MAX_VERTICES=10;
class Graph{
    private:
    int numVertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
    public:
    Graph(int vertices){
        numVertices=vertices;
        for(int i=0;i<numVertices;i++){
            for(int j=0;j<numVertices;j++){
                adjacencyMatrix[i][j]=0;
            }
        }
    }
    void addEdge(int u,int v){
        adjacencyMatrix[u][v]=1;
        adjacencyMatrix[v][u]=1;
    }
    void printMatrix(){
        for(int i=0;i<numVertices;i++){
            for(int j=0;numVertices;++){
                cout<<adjacencyMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}