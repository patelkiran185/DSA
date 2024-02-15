#include <iostream>
#include <stack>
#include <string>
using namespace std;

int evaluatePostfix(const string& expression) {
    stack<int> s;

    for (char i : expression) {
        if (isdigit(i)) {
            s.push(i - '0');
        } else {
            int val1 = s.top(); s.pop();
            int val2 = s.top(); s.pop();

            switch (i) {
                case '+': s.push(val2 + val1); break;
                case '-': s.push(val2 - val1); break;
                case '*': s.push(val2 * val1); break;
                case '/': s.push(val2 / val1); break;
            }
        }
    }
    return s.top();
}

int main() {
    string expression = "231*+9-";
    cout << "postfix evaluation: " << evaluatePostfix(expression) << "\n";
    return 0;
}