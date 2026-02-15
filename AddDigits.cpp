#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {  
            int sum = 0;
            while (num > 0) {
                sum += num % 10; 
                num /= 10;    
            }
            num = sum;   
        }
        return num;
    }
};

int main() {
    Solution sol;
    int number;

    cout << "Enter a number: ";
    cin >> number;

    int result = sol.addDigits(number);

    cout << "Single digit result: " << result << endl;

    return 0;
}
