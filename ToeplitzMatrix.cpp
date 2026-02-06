#include<iostream>
using namespace std;


bool isToeplitz(int M[][100], int m, int n)
{

    for(int i=0;i<m-1;i++)
    {
        for(int j=0;j<n-1;j++)
 {
    if(M[i][j]!=M[i+1][j+1])
    return false;
 }
    }
    return true;
}

int main()
{
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    int M[100][100];

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> M[i][j];
        }
    }

    if(isToeplitz(M, m, n))
        cout << "Matrix is Toeplitz\n";
    else
        cout << "Matrix is NOT Toeplitz\n";

    return 0;
}

