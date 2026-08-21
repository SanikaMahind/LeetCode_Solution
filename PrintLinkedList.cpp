#include <bits/stdc++.h>
using namespace std;

class ImmutableListNode {
public:
    int val;
    ImmutableListNode* next;

    ImmutableListNode(int x) {
        val = x;
        next = NULL;
    }

    void printValue() {
        cout << val << " ";
    }

    ImmutableListNode* getNext() {
        return next;
    }
};

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        if (head == NULL)
            return;

        printLinkedListInReverse(head->getNext());
        head->printValue();
    }
};

int main() {
    ImmutableListNode* head = new ImmutableListNode(1);
    head->next = new ImmutableListNode(2);
    head->next->next = new ImmutableListNode(3);
    head->next->next->next = new ImmutableListNode(4);

    Solution s;
    s.printLinkedListInReverse(head);

    return 0;
}
