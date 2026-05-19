#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> s;
    stack<int> minStack;

public:
    MinStack() {
        
    }

    void push(int val) {
        s.push(val);

        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop() {
        if (s.top() == minStack.top()) {
            minStack.pop();
        }

        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minStack.top();
    }
};

int main() {
    MinStack st;

    st.push(-2);
    st.push(0);
    st.push(-3);

    cout << "Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "Top Element: " << st.top() << endl;
    cout << "Minimum: " << st.getMin() << endl;

    return 0;
}