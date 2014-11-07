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

TreeNode *getTree(vector<int> &postorder, vector<int> &inorder, int start, int end) {
    if (postorder.size() == 0 || start > end) {
        return NULL;
    }

    // Get the current root
    TreeNode *currentRoot = new TreeNode(postorder.back());
    postorder.pop_back();

    if (postorder.size() == 0 || start == end) {
        return currentRoot;
    }

    // Find the position in inorder
    int position = find(inorder, currentRoot->val, start, end);

    // Get the left and right subtree
    TreeNode *right = getTree(postorder, inorder, position + 1, end);
    TreeNode *left = getTree(postorder, inorder, start, position - 1);

    // Attach the subtrees
    currentRoot->left = left;
    currentRoot->right = right;

    return currentRoot;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    return getTree(postorder, inorder, 0, inorder.size() - 1);
}

int main() {
    int pre[] = {1,2,3};
    int in[] = {2,1,3};

    vector<int> postorder(pre, pre + 3);
    vector<int> inorder(in, in + 3);

    buildTree(preorder, inorder);
}
