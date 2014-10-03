#include "lib/tree.cpp"

TreeNode* tailFlatten(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    if (root->left == NULL && root->right == NULL) {
        return root;
    }

    if (root->left == NULL && root->right != NULL) {
        return tailFlatten(root->right);
    }

    if (root->right == NULL && root->left != NULL) {
        root->right = root->left;
        root->left = NULL;
        return tailFlatten(root->right);
    }

    TreeNode* temp1 = tailFlatten(root->right);
    TreeNode* temp2 = tailFlatten(root->left);

    temp2->right = root->right;
    root->right = root->left;
    root->left = NULL;

    return temp1;
}

void flatten(TreeNode *root) {
    tailFlatten(root);
}
