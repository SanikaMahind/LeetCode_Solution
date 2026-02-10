#include<iostream>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) 


{
    int cnt=0;
    int sz1=s.size();
    int sz2=t.size();

    int i=0;
    int j=0;

    if(sz2<sz1)
    return false;

    while(i<sz1&&j<sz2)
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
            cnt++;
        
        }
        else{
            j++;

        }
    }
  if(sz1==cnt)
  return true;

  else
  return false;
}
};
int main() {
    string s, t;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    Solution obj;
    bool result = obj.isSubsequence(s, t);

    if (result)
        cout << "True: s is a subsequence of t" << endl;
    else
        cout << "False: s is NOT a subsequence of t" << endl;

    return 0;
}
