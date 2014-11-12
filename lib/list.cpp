#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode (int x): val(x), next(NULL) {}
};

void printList(ListNode *head) {
    ListNode *iterator = head;
    while (iterator != NULL) {
        std::cout << iterator->val << " ";
        iterator = iterator->next;
    }
    std::cout << std::endl;
}
