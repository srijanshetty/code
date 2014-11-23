#include <bits/stdc++.h>
#include "lib/tree.cpp"

using namespace std;

void dfs(TreeNode *root, int current, int &sum) {
    if (root == NULL) {
        return;
    }

    current = current * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
        sum += current;
    }

    dfs(root->left, current, sum);
    dfs(root->right, current, sum);
}

int sumNumbers(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;
    int current = 0;
    dfs(root, current, sum);

    return sum;
}

int main() {
    return 0;
}
