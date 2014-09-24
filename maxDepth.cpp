#include "lib/tree.cpp"

int maxDepth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    if (root->left == NULL && root->right != NULL) {
        return 1 + maxDepth(root->right);
    }

    if (root->right == NULL && root->left != NULL) {
        return 1 + maxDepth(root->left);
    }

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + ((leftDepth > rightDepth) ? leftDepth : rightDepth);
}

