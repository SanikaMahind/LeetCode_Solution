#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        vector<int> factorial(n,1);
        string result = "";

        
        for(int i = 1; i <= n; i++)
            numbers.push_back(i);

        
        for(int i = 1; i < n; i++)
            factorial[i] = factorial[i-1] * i;

        k--; 

        for(int i = n; i >= 1; i--) {
            int index = k / factorial[i-1];
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);

            k %= factorial[i-1];
        }

        return result;
    }
};

int main() {
    Solution s;
    int n = 3, k = 3;
    cout << "Permutation: " << s.getPermutation(n, k);
}