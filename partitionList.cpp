#include "lib/list.cpp"

using namespace std;

ListNode *partition(ListNode* head, int k) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* newHead = new ListNode(0);
    newHead->next = head;

    ListNode* prev = newHead;
    ListNode* iter = head;
    ListNode* greater = new ListNode(0);
    ListNode* greaterTail = greater;

    while (iter != NULL) {
        if (iter->val >= k) {
            greaterTail->next = iter;

            prev->next = iter->next;
            iter = iter->next;

            greaterTail = greaterTail->next;
            greaterTail->next = NULL;
        } else {
            prev = iter;
            iter = iter->next;
        }
    }

    if (newHead->next != NULL) {
        head = newHead->next;
    }

    if (greater->next != NULL) {
        prev->next = greater->next;
    }

    return head;
}


int main() {
    ListNode head(10);
    ListNode second(20);
    ListNode third(30);
    ListNode fourth(40);
    ListNode fifth(50);
    head.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = &fifth;

    int k;
    cin >> k;
    ListNode* newHead = partition(&head, k);
    ListNode *temp = newHead;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp=temp->next;
    }

    return 0;
}
