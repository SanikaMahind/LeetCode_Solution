#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {

        if (nums.size() % k != 0)
            return false;

        map<int, int> freq;

        for (int num : nums)
            freq[num]++;

        while (!freq.empty()) {

            int first = freq.begin()->first;

            for (int i = 0; i < k; i++) {

                int current = first + i;

                if (freq.find(current) == freq.end())
                    return false;

                freq[current]--;

                if (freq[current] == 0)
                    freq.erase(current);
            }
        }

        return true;
    }
};

int main() {

    Solution obj;

    vector<int> nums = {1,2,3,3,4,4,5,6};
    int k = 4;

    if (obj.isPossibleDivide(nums, k))
        cout << "true";
    else
        cout << "false";

    return 0;
}