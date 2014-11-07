#include "lib/tree.cpp"
#include "lib/list.cpp"

using namespace std;

TreeNode *sortedListToBST(ListNode* head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        return new TreeNode(head->val);
    }

    int length = 0;
    ListNode *iterator = head;
    while (iterator != NULL) {
        length++;
        iterator = iterator->next;
    }

    int middle = length / 2;
    int i = 1;
    ListNode *previous = head;
    iterator = head->next;
    while ( i != middle ) {
        previous = iterator;
        iterator = iterator->next;
        i++;
    }

    previous->next = NULL;
    TreeNode *left = sortedListToBST(head);
    TreeNode *right = sortedListToBST(iterator->next);

    TreeNode *currentRoot = new TreeNode(iterator->val);
    currentRoot->left = left;
    currentRoot->right = right;

    return currentRoot;
}
