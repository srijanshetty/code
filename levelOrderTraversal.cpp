#include "lib/tree.cpp"
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > levelOrderTraversal(TreeNode *root) {
    vector<vector<int> > traversal;

    if (root == NULL) {
        return traversal;
    }

    queue<TreeNode*> previousLevel;
    previousLevel.push(root);

    TreeNode* iterator;
    while (!previousLevel.empty()) {
        vector<int> nodes;

        iterator = previousLevel.front();
        queue<TreeNode*> currentLevel;
        for (; !previousLevel.empty(); previousLevel.pop(), iterator = previousLevel.front()) {
            nodes.push_back(iterator->val);

            if (iterator->left != NULL) {
                currentLevel.push(iterator->left);
            }

            if (iterator->right != NULL) {
                currentLevel.push(iterator->right);
            }
        }
        traversal.push_back(nodes);

        previousLevel = currentLevel;
    }

    reverse(traversal.begin(), traversal.end());
    return traversal;
}

int main() {
    TreeNode root = TreeNode(1);
    TreeNode left = TreeNode(2);
    TreeNode right = TreeNode(3);
    root.left = &left;
    root.right = &right;

    levelOrderTraversal(&root);

}
