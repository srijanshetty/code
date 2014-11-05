#include "lib/tree.cpp"
#include <vector>
#include <stack>

using namespace std;

void isBST(TreeNode *root) {
    vector<int> traversal;

    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return true;
    }

    TreeNode *current = root;
    stack<TreeNode *> callStack;
    while (!callStack.empty() || current != NULL) {
        if (current != NULL) {
            callStack.push(current);
            current = current->left;
            continue;
        }

        if (current == NULL && !callStack.empty()) {
            current = callStack.top();
            traversal.push_back(current->val);
            current = current->right;
            callStack.pop();
        }
    }

    bool flag = true;
    vector<int>::iterator i = traversal.begin();
    int prev = *i;
    ++i;

    for (; i != traversal.end(); ++i) {
        if (*i <= prev) {
            flag = false;
            break;
        }

        prev = *i;
    }

    return flag;
}

