#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;   // original matrix size
    cout << "Enter rows and columns of original matrix: ";
    cin >> m >> n;

    vector<vector<int>> M1(m, vector<int>(n));

    cout << "Enter elements of original matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> M1[i][j];

    int r, c;   // new matrix size
    cout << "Enter rows and columns for reshaped matrix: ";
    cin >> r >> c;

    // Check if reshape is possible
    if (m * n != r * c)
    {
        cout << "Reshape not possible!\n";
        return 0;
    }

    vector<vector<int>> M2(r, vector<int>(c));

    int a = 0, b = 0;

    // Fill new matrix row-wise
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M2[a][b] = M1[i][j];
            b++;

            if (b == c)
            {
                a++;
                b = 0;
            }
        }
    }

    cout << "\nReshaped Matrix:\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << M2[i][j] << " ";
        cout << endl;
    }

    return 0;
}
