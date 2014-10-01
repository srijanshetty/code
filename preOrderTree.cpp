#include <stack>
#include <vector>
#include "lib/tree.cpp"

using namespace std;

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> order;

    if (root == NULL) {
        return order;
    }

    stack<TreeNode*> s;
    s.push(root);

    TreeNode* temp;
    while(!s.empty()) {
        temp = s.top();
        s.pop();

        order.push_back(temp->val);

        if (temp->right != NULL) {
            s.push(temp->right);
        }

        if (temp->left != NULL) {
            s.push(temp->left);
        }
    }

    return order;
}
