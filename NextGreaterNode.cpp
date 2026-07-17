#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

vector<int> nextLargerNodes(ListNode* head) {
    vector<int> v, ans;
    while (head) {
        v.push_back(head->val);
        head = head->next;
    }

    ans.assign(v.size(), 0);
    stack<int> st;

    for (int i = 0; i < v.size(); i++) {
        while (!st.empty() && v[i] > v[st.top()]) {
            ans[st.top()] = v[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int main() {
    int n, x;
    cin >> n;

    ListNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        ListNode *node = new ListNode(x);
        if (!head) head = tail = node;
        else tail->next = node, tail = node;
    }

    vector<int> ans = nextLargerNodes(head);

    for (int x : ans)
        cout << x << " ";

    return 0;
}