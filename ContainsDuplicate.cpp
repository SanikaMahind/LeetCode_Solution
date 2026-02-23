#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;   
        }
        seen.insert(num);
    }

    return false;   
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 1};

    if (containsDuplicate(nums))
        cout << "True";
    else
        cout << "False";
}