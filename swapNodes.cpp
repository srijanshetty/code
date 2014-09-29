#include "lib/list.cpp"

using namespace std;

ListNode* swapNodes(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* fakeHead = new ListNode(0);
    fakeHead->next = head;

    ListNode* prev = fakeHead;
    ListNode* current = head;
    ListNode* temp;
    while (current != NULL && current->next != NULL) {
        temp = current->next->next;
        prev->next = current->next;
        current->next->next = current;
        current->next = temp;

        prev = current;
        current = temp;
    }

    head = fakeHead->next;

    return head;
}

int main() {
    ListNode *head, *second, *third, *fourth, *fifth, *newHead, *temp;

    // Normal List
    cout << endl << "Normal List with odd elements" << endl << endl;
    head = new ListNode(10);
    second = new ListNode(20);
    third = new ListNode(30);
    fourth = new ListNode(40);
    fifth = new ListNode(50);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    newHead = swapNodes(head);
    temp = newHead;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp=temp->next;
    }

    // Normal List
    cout << endl << "Normal List with even elements" << endl << endl;
    head = new ListNode(10);
    second = new ListNode(20);
    third = new ListNode(30);
    fourth = new ListNode(40);
    head->next = second;
    second->next = third;
    third->next = fourth;

    newHead = swapNodes(head);
    temp = newHead;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp=temp->next;
    }


    // NULL head
    cout << endl << "NULL head" << endl << endl;
    head = NULL;
    newHead = swapNodes(head);
    temp = newHead;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp=temp->next;
    }

    // Only one element
    cout << endl << "Single head" << endl << endl;
    head = new ListNode(10);
    head->next = NULL;
    newHead = swapNodes(head);
    temp = newHead;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp=temp->next;
    }

    return 0;
}
