#include "lib/list.cpp"

ListNode *mergeLists(ListNode* l1, ListNode* l2) {
    ListNode* l3 = new ListNode(0);

    ListNode* iter1 = l1;
    ListNode* iter2 = l2;
    ListNode* iter3 = l3;

    while (iter1 != NULL && iter2 != NULL) {
        if (iter1->val < iter2->val) {
            iter3->next = iter1;
            iter3 = iter3->next;

            iter1 = iter1->next;
            iter3->next = NULL;
        } else {
            iter3->next = iter2;
            iter3 = iter3->next;

            iter2 = iter2->next;
            iter3->next = NULL;
        }
    }

    if (iter1 == NULL) {
        while (iter2 != NULL) {
            iter3->next = iter2;
            iter3 = iter3->next;

            iter2 = iter2->next;
            iter3->next = NULL;
        }
    }

    if (iter2 == NULL) {
        while (iter1 !=NULL) {
            iter3->next = iter1;
            iter3 = iter3->next;

            iter1 = iter1->next;
            iter3->next = NULL;
        }
    }

    l3 = l3->next;
    return l3;
}
