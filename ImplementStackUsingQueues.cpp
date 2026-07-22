#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);

        for (int i = 0; i < q.size() - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack s;

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top: " << s.top() << endl;

    cout << "Pop: " << s.pop() << endl;

    cout << "Top after pop: " << s.top() << endl;

    if (s.empty())
        cout << "Stack is Empty";
    else
        cout << "Stack is Not Empty";

    return 0;
}