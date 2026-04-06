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

bool hasCycle(ListNode *head) {
    if (head == NULL) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;          
        fast = fast->next->next;   

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
   
    ListNode* head = new ListNode(1);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(3);
    ListNode* fourth = new ListNode(4);

 
    head->next = second;
    second->next = third;
    third->next = fourth;

  
    fourth->next = second;

    if (hasCycle(head))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle" << endl;

    return 0;
}