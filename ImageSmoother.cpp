#include <iostream>
using namespace std;

int main()
{
    int rows, col;
    cout << "Enter rows and columns: ";
    cin >> rows >> col;

    int M[100][100];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < col; j++)
            cin >> M[i][j];

    int Lr = rows - 1;
    int Lc = col - 1;

    int result[100][100];

    for (int rI = 0; rI < rows; rI++)
    {
        for (int cI = 0; cI < col; cI++)
        {
            int sum = 0;
            int cnt = 0;

            int sR = (rI == 0) ? 0 : rI - 1;
            int eR = (rI == Lr) ? rI : rI + 1;
            int sC = (cI == 0) ? 0 : cI - 1;
            int eC = (cI == Lc) ? cI : cI + 1;

            for (int i = sR; i <= eR; i++)
                for (int j = sC; j <= eC; j++)
                {
                    sum += M[i][j];
                    cnt++;
                }

            result[rI][cI] = sum / cnt;
        }
    }

    cout << "\nNew matrix after averaging neighbors:\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < col; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}
