#include "lib/tree.cpp"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> postorder(TreeNode *root) {
    vector<int> traversal;
    if (root == NULL) {
        return traversal;
    }

    stack<TreeNode*> order;
    order.push(root);

    TreeNode* iterator;
    while (!order.empty()) {
        iterator = order.top();
        order.pop();
        traversal.insert(traversal.begin(), iterator->val);

        if (iterator->left != NULL) {
            order.push(iterator->left);
        }

        if (iterator->right != NULL) {
            order.push(iterator->right);
        }

    }

    return traversal;
}
