#include "lib/list.cpp"

bool hasCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    ListNode *turtle = head;
    ListNode *rabbit = head->next;

    while (rabbit != NULL) {
        if ( rabbit == turtle ) {
            return true;
        }

        if (rabbit->next != NULL) {
            rabbit = rabbit->next->next;
        } else {
            return false;
        }

        turtle = turtle->next;
    }

    return false;
}
