#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gains) {
        int maxA = 0;
        int currA = 0;

        for (int i = 0; i < gains.size(); i++) {
            currA += gains[i];
            
            if (currA > maxA) {
                maxA = currA;
            }
        }

        return maxA;
    }
};

int main() {
    int n;
    cout << "Enter number of gains: ";
    cin >> n;

    vector<int> gains(n);
    cout << "Enter the gains values: ";
    for (int i = 0; i < n; i++) {
        cin >> gains[i];
    }

    Solution obj;
    int result = obj.largestAltitude(gains);

    cout << "Highest Altitude: " << result << endl;

    return 0;
}

