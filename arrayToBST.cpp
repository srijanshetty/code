#include "lib/tree.cpp"
#include <vector>

using namespace std;

TreeNode *convertBST(vector<int> &num, int first, int last) {
    if (first > last) {
        return NULL;
    }

    if ( first == last ) {
        return new TreeNode(num.at(first));
    }

    int middle = (first + last) / 2;

    TreeNode* root = new TreeNode(num.at(middle));
    root->left = convertBST(num, first, middle - 1);
    root->right = convertBST(num, middle + 1, last);

    return root;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
    if (num.size() == 0) {
        return NULL;
    }

    return convertBST(num, 0, num.size() - 1);
}
