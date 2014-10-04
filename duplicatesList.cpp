#include "lib/list.cpp"

ListNode* deleteDuplicates(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* prunedHead = new ListNode(head->val - 1);
    ListNode* prunedIterator = prunedHead;
    ListNode* temp;

    ListNode* prev = head;
    ListNode* iterator = head->next;

    while (iterator != NULL) {
        if (prev->val != iterator->val) {
            temp = new ListNode(prev->val);
            prunedIterator->next = temp;
            prunedIterator = temp;
        } else {
            while (iterator != NULL && iterator->val == prev->val) {
                iterator = iterator->next;
            }

            if (iterator == NULL) {
                break;
            }
        }

        if (iterator->next == NULL) {
            temp = new ListNode(iterator->val);
            prunedIterator->next = temp;
            break;
        }

        prev = iterator;
        iterator = iterator->next;
    }

    return prunedHead->next;
}
