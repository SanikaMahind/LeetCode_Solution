#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    
    if (l1 != NULL)
        tail->next = l1;
    else
        tail->next = l2;

    return dummy->next;
}


void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}


int main() {
    
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    cout << "List 1:\n";
    printList(l1);

    cout << "List 2:\n";
    printList(l2);

    ListNode* merged = mergeTwoLists(l1, l2);

    cout << "Merged List:\n";
    printList(merged);

    return 0;
}