#include <iostream>
#include <stack>
using namespace std;

bool isPalindrome(string s) {
    int length = s.size();
    stack<char> st;

    // Calculate the midpoint of the string
    int mid = length / 2;

    // Push the first half of the string onto the stack
    for (int i = 0; i < mid; i++) {
        st.push(s[i]);
    }

    // Adjust the index to the middle character if the length is odd
    int i = (length % 2 == 0) ? mid : mid + 1;

    // Compare the second half of the string with the stack
    while (i < length) {
        char ele = st.top();
        st.pop();
        
        // Compare the character from the stack with the current character
        if (ele != s[i]) {
            return false;
        }
        i++;
    }

    // If all characters match, the string is a palindrome
    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    if (isPalindrome(s)) {
        cout << "Palindrome\n";
    } else {
        cout << "Not Palindrome\n";
    }
    return 0;
}