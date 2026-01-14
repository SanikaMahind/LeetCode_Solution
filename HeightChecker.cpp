#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int HeightChecker(vector<int>& h)
{

int Sz=h.size();

vector<int>e(h);
sort(e.begin(),e.end());

int cnt=0;

for(int i=0;i<Sz;i++)
{
    if(h[i]!=e[i])
    cnt++;
}
return cnt;
};
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> h(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> h[i];

    int result = HeightChecker(h);
    cout << "Count = " << result << endl;

    return 0;
}