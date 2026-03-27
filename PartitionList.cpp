#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* partition(ListNode* head, int x) {
    ListNode* smallHead = new ListNode(0);
    ListNode* bigHead = new ListNode(0);

    ListNode* small = smallHead;
    ListNode* big = bigHead;

    while (head != NULL) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            big->next = head;
            big = big->next;
        }
        head = head->next;
    }

    big->next = NULL;
    small->next = bigHead->next;

    return smallHead->next;
}


void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


int main() {
    
    ListNode* head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);

    int x = 3;

    cout << "Original List: ";
    printList(head);

    head = partition(head, x);

    cout << "Partitioned List: ";
    printList(head);

    return 0;
}