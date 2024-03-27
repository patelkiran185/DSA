#include <iostream>
using namespace std;
class Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
Node* createBST(int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int mid = start + (end - start) / 2;
    Node* root = new Node(mid);
    root->left = createBST(start, mid - 1);
    root->right = createBST(mid + 1, end);
    return root;
}
void playGame(Node* root) {
    cout << "Think of a number between 1 and 100. I will try to guess it!" << endl;
    Node* current = root;
    while (current != nullptr) {
        cout << "Is your number " << current->data << "? (Enter 'l' if your number is lower, 'h' if higher, or 'y' if correct): ";
        char response;
        cin >> response;
        if (response == 'y') {
            cout << "Great! I guessed your number." << endl;
            break;
        } else if (response == 'l') {
            current = current->left;
        } else if (response == 'h') {
            current = current->right;
        } else {
            cout << "Invalid input. Please enter 'l', 'h', or 'y'." << endl;
        }
    }
    if (current == nullptr) {
        cout << "I couldn't guess your number." << endl;
    }
}

int main() {
    Node* root = createBST(1, 100);
    playGame(root);
    return 0;
}
