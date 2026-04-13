#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> logs(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> logs[i];
    }

    cout << "Consecutive Numbers: ";

    for (int i = 0; i < n - 2; i++)
    {
        if (logs[i] == logs[i + 1] && logs[i] == logs[i + 2])
        {
            if (i == 0 || logs[i] != logs[i - 1])
            {
                cout << logs[i] << " ";
            }
        }
    }

    cout << endl;

    return 0;
}