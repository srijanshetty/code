#include "lib/tree.cpp"
#include <vector>
#include <queue>
#include <string>

using namespace std;

bool isPallindrome(string word) {
    if (word.size() == 0) {
        return true;
    }

    int back = word.size() - 1;
    int front = 0;

    while (front <= back) {
        if (word[front] != word[back]) {
            return false;
        }
        front++;
        back--;
    }

    return true;
}

bool isSymmetric(TreeNode *root) {
    if (root == NULL) {
        return true;
    }

    queue<TreeNode*> previous;
    string word;

    TreeNode* it;
    previous.push(root);
    while (!previous.empty()) {
        queue<TreeNode*> current;
        while(!previous.empty()) {
            it = previous.front(); previous.pop();

            if (it->left != NULL) {
                current.push(it->left);
                word.push_back('0' + it->left->val);
            } else {
                word.push_back('#');
            }

            if (it->right != NULL) {
                current.push(it->right);
                word.push_back('0' + it->right->val);
            } else {
                word.push_back('#');
            }
        }

        previous = current;

        if (!isPallindrome(word)) {
            return false;
        }

        word = "";
    }


    return true;
}

int main() {
    cout << isPallindrome("srs") << endl;
    cout << isPallindrome("isrs") << endl;
    cout << isPallindrome("siris") << endl;
    return 0;
}
