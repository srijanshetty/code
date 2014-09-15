#include "lib/tree.cpp"

int minDepth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    if (root->right == NULL && root->left == NULL) {
        return 1;
    }

    if (root->right != NULL && root->left == NULL) {
        return 1 + minDepth(root->right);
    }

    if (root->left != NULL && root->right == NULL) {
        return 1 + minDepth(root->left);
    }

    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    int depth = (leftDepth < rightDepth) ? leftDepth : rightDepth;

    return 1 + depth;
}
