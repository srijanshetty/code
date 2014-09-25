#include "lib/tree.cpp"

bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL) {
        return false;
    }

    if (root->right == NULL && root->left == NULL) {
        return (sum == root->val);
    }

    if (root->right == NULL && root->left != NULL) {
        return hasPathSum(root->left, sum - root->val);
    }

    if (root->left == NULL && root->right!= NULL) {
        return hasPathSum(root->right, sum - root->val);
    }

    return hasPathSum(root->right, sum - root->val) || hasPathSum(root->left, sum - root->val);
}
