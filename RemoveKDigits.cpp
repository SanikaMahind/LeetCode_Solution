#include <iostream>
#include <stack>
using namespace std;

string removeKdigits(string num, int k)
{
    stack<char> st;

    for(char digit : num)
    {
        while(!st.empty() && k > 0 && st.top() > digit)
        {
            st.pop();
            k--;
        }
        st.push(digit);
    
    while(k > 0 && !st.empty())
    {
        st.pop();
        k--;
    }

    
    string result = "";
    while(!st.empty())
    {
        result = st.top() + result;
        st.pop();
    }

    
    int i = 0;
    while(i < result.size() && result[i] == '0')
        i++;

    result = result.substr(i);

    if(result == "")
        return "0";

    return result;
}

int main()
{
    string num = "1432219";
    int k = 3;

    cout << "Smallest Number: " << removeKdigits(num, k);

    return 0;
}