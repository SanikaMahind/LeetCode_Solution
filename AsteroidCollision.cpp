#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids)
{
    stack<int> st;

    for(int a : asteroids)
    {
        bool destroyed = false;

        while(!st.empty() && st.top() > 0 && a < 0)
        {
            if(abs(st.top()) < abs(a))
            {
                st.pop();
                continue;
            }
            else if(abs(st.top()) == abs(a))
            {
                st.pop();
            }

            destroyed = true;
            break;
        }

        if(!destroyed)
        {
            st.push(a);
        }
    }

    vector<int> result(st.size());

    for(int i = st.size()-1; i >= 0; i--)
    {
        result[i] = st.top();
        st.pop();
    }

    return result;
}

int main()
{
    vector<int> ast = {5,10,-5};

    vector<int> ans = asteroidCollision(ast);

    for(int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}