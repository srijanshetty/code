#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeLinkNode {
    TreeLinkNode* left;
    TreeLinkNode* right;
    TreeLinkNode* next;
};

void connect(TreeLinkNode *root) {
    if (root == NULL) {
        return;
    }

    queue<TreeLinkNode*> previousLevel;
    previousLevel.push(root);

    TreeLinkNode* iterator;
    while (!previousLevel.empty()) {

        iterator = previousLevel.front();
        queue<TreeLinkNode*> currentLevel;
        for (; !previousLevel.empty(); iterator = previousLevel.front()) {
            previousLevel.pop();

            if (previousLevel.empty()) {
                iterator->next = NULL;
            } else {
                iterator->next = previousLevel.front();
            }

            if (iterator->left != NULL) {
                currentLevel.push(iterator->left);
            }

            if (iterator->right != NULL) {
                currentLevel.push(iterator->right);
            }
        }

        previousLevel = currentLevel;
    }
}

int main() {
    return 0;
}
