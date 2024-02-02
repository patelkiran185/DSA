#include<iostream>
using namespace std;
int factorial(int a);
int factorial(int a){
    if(a==0){
        return 1;
    }
    else if(a==1) return 1;
    else return a*factorial(a-1);
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int sum=0;
    int i=0;
    while(i<n){
        sum += factorial(i+1);
        i+=1;
    }
    cout<<"Arthemetic sum of "<<n << " is "<<sum;
    return 0;
}