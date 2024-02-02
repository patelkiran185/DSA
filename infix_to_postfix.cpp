#include<iostream>
#include<stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;
    for (char& c : infix) {
        if (isOperator(c)) {
            s.push(c);
        } else if (c == '(') {
            // do nothing
        } else if (c == ')') {
            postfix += s.top();
            s.pop();
        } else { // operand
            postfix += c;
        }
    }
    return postfix;
}

int main() {
    string infix = "((a+b)*(c-d))";
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}