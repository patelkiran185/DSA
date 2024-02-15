#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() {
        root = NULL;
    }

    int findSecondMinimum() {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        findSecondMinimumHelper(root, min1, min2);
        return (min2 == INT_MAX) ? -1 : min2;
    }

private:
    void findSecondMinimumHelper(TreeNode* node, int& min1, int& min2) {
        if (node == NULL) {
            return;
        }

        if (node->val < min1) {
            min2 = min1;
            min1 = node->val;
        } else if (node->val > min1 && node->val < min2) {
            min2 = node->val;
        }

        findSecondMinimumHelper(node->left, min1, min2);
        findSecondMinimumHelper(node->right, min1, min2);
    }
};

int main() {
    BinaryTree tree;
    tree.root = new TreeNode(2);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(5);
    tree.root->right->left = new TreeNode(5);
    tree.root->right->right = new TreeNode(7);

    int secondMin = tree.findSecondMinimum();

    if (secondMin != -1) {
        cout << "The second minimum node is: " << secondMin << endl;
    } else {
        cout << "No second minimum node exists in the binary tree." << endl;
    }

    delete tree.root->left;
    delete tree.root->right->left;
    delete tree.root->right->right;
    delete tree.root;

    return 0;
}



