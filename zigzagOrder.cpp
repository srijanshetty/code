#include "lib/tree.cpp"
#include <deque>
#include <vector>

using namespace std;

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > traversal;

    if (root == NULL) {
        return traversal;
    }

     deque<TreeNode*> previousLevel;
     bool order = true;
     previousLevel.push_back(root);

     TreeNode *iterator;
     while(!previousLevel.empty()) {

         deque<TreeNode*> currentLevel;
         vector<int> nodes;
         while (!previousLevel.empty()) {
             // Get the iterator
             if (order) {
                 iterator = previousLevel.front();
                 previousLevel.pop_front();

                 if (iterator->left != NULL) {
                     currentLevel.push_back(iterator->left);
                 }

                 if (iterator->right != NULL) {
                     currentLevel.push_back(iterator->right);
                 }
             } else {
                 iterator = previousLevel.back();
                 previousLevel.pop_back();

                 if (iterator->right != NULL) {
                     currentLevel.push_front(iterator->right);
                 }

                 if (iterator->left != NULL) {
                     currentLevel.push_front(iterator->left);
                 }
             }

             nodes.push_back(iterator->val);
         }

         traversal.push_back(nodes);
         order = !order;
         previousLevel = currentLevel;
     }

     return traversal;
}
