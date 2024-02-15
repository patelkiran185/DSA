#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void sortQueue(queue<int> &q) {
    stack<int> s;
    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        while (!s.empty() && s.top() < temp) {
            q.push(s.top());
            s.pop();
        }
        s.push(temp);
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

void displayQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(5);
    q.push(3);
    q.push(7);
    q.push(1);
    q.push(2);
    cout << "Original queue: ";
    displayQueue(q); // Original queue: 5 3 7 1 2
    sortQueue(q);
    cout << "Sorted queue: ";
    displayQueue(q); // Sorted queue: 7 5 3 2 1
    return 0;
}

