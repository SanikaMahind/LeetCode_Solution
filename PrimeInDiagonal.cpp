#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to check prime
bool isPrime(int p)
{
    if (p < 2)
        return false;

    for (int i = 2; i <= sqrt(p); i++)
    {
        if (p % i == 0)
            return false;
    }
    return true;
}

int largestPrimeDiagonal(vector<vector<int>> &nums, int n)
{
    int largest_prime = 0;

    for(int i=0;i<n;i++)
{
    if(isPrime(nums[i][i]))
    {
    largest_prime=max(largest_prime,nums[i][i]);
}

}

for(int i=0;i<n;i++)
{
    if(isPrime(nums[i][n-i-1]))
    {
        largest_prime= max(nums[i][n-i-1],largest_prime);
    }
}
  return largest_prime;

}

int main()
{
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    vector<vector<int>> nums(n, vector<int>(n));

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> nums[i][j];
        }
    }

    int result = largestPrimeDiagonal(nums, n);

    if (result == 0)
        cout << "No prime number found on diagonals.\n";
    else
        cout << "Largest prime on diagonals: " << result << endl;

    return 0;
}
