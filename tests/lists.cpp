#include "../deleteDuplicates.cpp"

using namespace std;

int main() {
    ListNode *head, *second, *third, *fourth, *fifth, *newHead, *temp;

    // Normal List
    cout << endl << "Normal List" << endl << endl;
    head = new ListNode(10);
    second = new ListNode(20);
    third = new ListNode(30);
    fourth = new ListNode(40);
    fifth = new ListNode(50);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    newHead = deleteDuplicates(head);
    temp = newHead;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp=temp->next;
    }

    // Identical List
    cout << endl << "Identical List" << endl << endl;
    head = new ListNode(10);
    second = new ListNode(10);
    third = new ListNode(10);
    fourth = new ListNode(10);
    fifth = new ListNode(10);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    newHead = deleteDuplicates(head);
    temp = newHead;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp=temp->next;
    }

    // List with duplicates
    cout << endl << "List with duplicates" << endl << endl;
    head = new ListNode(10);
    second = new ListNode(20);
    third = new ListNode(30);
    fourth = new ListNode(10);
    fifth = new ListNode(10);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    newHead = deleteDuplicates(head);
    temp = newHead;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp=temp->next;
    }

    // NULL head
    cout << endl << "NULL head" << endl << endl;
    head = NULL;
    newHead = deleteDuplicates(head);
    temp = newHead;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp=temp->next;
    }

    // Only one element
    cout << endl << "Single head" << endl << endl;
    head = new ListNode(10);
    head->next = NULL;
    newHead = deleteDuplicates(head);
    temp = newHead;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp=temp->next;
    }

    return 0;
}
