#include "lib/tree.cpp"
#include <vector>

using namespace std;

int find(vector<int> list, int element, int first, int last) {
    for (int i = first; i <= last; ++i) {
        if (list[i] == element) {
            return i;
        }
    }

    return -1;
}

TreeNode *getTree(vector<int> &preorder, vector<int> &inorder, int start, int end) {
    if (preorder.size() == 0 || start > end) {
        return NULL;
    }

    // Get the current root
    TreeNode *currentRoot = new TreeNode(preorder[0]);
    preorder.erase(preorder.begin());

    if (preorder.size() == 0 || start == end) {
        return currentRoot;
    }

    // Find the position in inorder
    int position = find(inorder, currentRoot->val, start, end);

    // Get the left and right subtree
    TreeNode *left = getTree(preorder, inorder, start, position - 1);
    TreeNode *right = getTree(preorder, inorder, position + 1, end);

    // Attach the subtrees
    currentRoot->left = left;
    currentRoot->right = right;

    return currentRoot;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    return getTree(preorder, inorder, 0, inorder.size() - 1);
}

int main() {
    int pre[] = {1,2,3};
    int in[] = {2,1,3};

    vector<int> preorder(pre, pre + 3);
    vector<int> inorder(in, in + 3);

    buildTree(preorder, inorder);
}
