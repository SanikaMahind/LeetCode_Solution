#include <iostream>
#include <vector>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{


int m=matrix.size();
int n=matrix[0].size();

vector<int> cols (n,0);
vector<int>rows(m,0);

for(int i=0;i<m;i++)
{
    for (int j = 0; j < n; j++){

    
    if(matrix[i][j]==0)
    {
        cols[j]=1;
        rows[i]=1;

    }
}

}

for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        if(cols[j]==1||rows[i]==1)
        {
            matrix[i][j]=0;
        }
    }
}
}

int main()
{
    int m, n;
    cout << "Enter rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    setZeroes(matrix);

    cout << "\nMatrix after setting zeroes:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}