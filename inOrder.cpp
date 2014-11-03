#include <iostream>
#include <vector>
#include <stack>
#include "lib/tree.cpp"

using namespace std;

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> traversal;
    if (root == NULL) {
        return traversal;
    }

    stack<TreeNode *> S;
    TreeNode* current = root;

    while (current != NULL || !S.empty()) {
        if (current != NULL) {
            S.push(current);
            current = current->left;
            continue;
        }

        if (current == NULL && !S.empty()) {
            TreeNode* temp = S.top();
            traversal.push_back(temp->val);
            S.pop();
            current = temp->right;
        }
    }


    return traversal;
}
