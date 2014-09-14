#include "lib/list.cpp"

using namespace std;

ListNode *rotateRight(ListNode* head, int k) {
    if (head != NULL) {
        int size = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
            ++size;
        }
        tail->next = head;

        k = k%size;

        int i = 0;
        ListNode* temp = head;
        for ( ; i<size-k-1; ++i) {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;
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
    ListNode* newHead = rotateRight(&head, k);
    ListNode *temp = newHead;
    while (temp != NULL) {
        cout << temp->val << endl;
        temp=temp->next;
    }

    return 0;
}
