#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter rows and columns of original matrix: ";
    cin >> m >> n;

    vector<int> temp;   // store elements in 1D

    cout << "Enter matrix row by row:\n";
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
    }

    int r, c;
    cout << "Enter rows and columns of reshaped matrix: ";
    cin >> r >> c;

    if(m * n != r * c)
    {
        cout << "Reshape not possible!\n";
        return 0;
    }

    vector<vector<int>> M2(r, vector<int>(c));

    int k = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            M2[i][j] = temp[k++];
        }
    }

    cout << "\nReshaped Matrix:\n";
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cout << M2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

