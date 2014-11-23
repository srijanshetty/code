#include "lib/list.cpp"
#include <climits>

using namespace std;

ListNode *insertionSortList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode *start = new ListNode(INT_MIN);
    ListNode *end = new ListNode(INT_MAX);
    start->next = end;

    ListNode *prev;
    ListNode *it;
    while (head != NULL) {
        prev = start;
        it = start->next;
        while (it != NULL) {
            if (head->val >= prev->val && head->val < it->val) {
                break;
            }

            prev = it;
            it = it->next;
        }

        prev->next = head;
        head = head->next;
        prev->next->next = it;
    }

    start = start->next;
    it = start;
    while ( it->next->next != NULL) {
        it = it->next;
    }

    it->next = NULL;

    return start;
}

int main() {

    ListNode *head = new ListNode (5);
    ListNode *first = new ListNode (4);
    ListNode *second = new ListNode (3);
    ListNode *third = new ListNode (2);
    ListNode *fourth = new ListNode (1);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;

    ListNode *start = insertionSortList(head);

    ListNode *it = start;
    while (it != NULL) {
        cout << it->val << " ";
        it = it->next;
    }
    cout << endl;

    return 0;
}
