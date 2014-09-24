#include "lib/list.cpp"

ListNode *deleteDuplicates (ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Create a fake head
    ListNode *fakeHead = new ListNode (head->val - 1);
    fakeHead->next = head;

    // Pointers for iteration
    ListNode *prev = fakeHead;
    ListNode *temp = head;

    while (temp != NULL) {
        if (temp->val == prev->val) {
            prev->next = temp->next;
        } else {
            prev = temp;
        }

        temp = temp->next;
    }

    head = fakeHead->next;
    return head;
}
