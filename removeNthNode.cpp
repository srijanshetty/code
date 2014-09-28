#include "lib/list.cpp"
#include <iostream>

using namespace std;

ListNode* removeNthNode(ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }

    int i = 1;
    ListNode* rabbit = head;
    while (rabbit != NULL && i <= n) {
        rabbit = rabbit->next;
        ++i;
    }

    if (rabbit != NULL) {
        ListNode* turtle = head;

        while (rabbit->next != NULL) {
            turtle = turtle->next;
            rabbit = rabbit->next;
        }

        turtle->next = turtle->next->next;
    } else if (rabbit == NULL && i == n + 1) {
        head = head->next;
    }

    return head;
}

int main() {
    ListNode *head, *second, *third, *fourth, *fifth, *newHead, *temp;

    // Normal List
    cout << endl << "Normal List" << endl << endl;
    head = new ListNode(10);
    second = new ListNode(20);
    third = new ListNode(30);
    head->next = second;
    second->next = third;

    newHead = removeNthNode(head, 3);
    temp = newHead;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp=temp->next;
    }

    return 0;
}
