// valid paranthesis
#include<iostream>
using namespace std;
#include<stack>
class BB{
    public:
        bool brdr(string str){
            stack<char>st;
            for(int i =0;i<str.length();i++){
                char c = str[i];
                if(st.empty()){
                    st.push(c);
                }
                else if((st.top() =='(' && c ==')')||(st.top()=='[' && c==']')||(st.top()=='{' && c=='}')){
                    st.pop();
                }
                else{
                    st.push(c);
                }
                
            }
            return st.empty();
        }
    };
int main(){
    BB bb;
    string str;
    cout<<"enter string; ";
    cin>>str;
    bb.brdr(str);
    if(bb.brdr(str)){
        cout<<"valid";
    }
    else{
        cout<<"invalid";
    }
    return 0;
}