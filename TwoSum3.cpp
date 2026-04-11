#include <iostream>
#include <unordered_map>
using namespace std;

class TwoSum {
private:
    unordered_map<int, int> mp;

public:
   
    void add(int number) {
        mp[number]++;
    }

    bool find(int value) {
        for (auto &it : mp) {
            int num = it.first;
            int complement = value - num;

            if (complement != num) {
                if (mp.find(complement) != mp.end()) {
                    return true;
                }
            }
         
            else {
                if (it.second > 1) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    TwoSum obj;

    obj.add(1);
    obj.add(3);
    obj.add(5);

    cout << obj.find(4) << endl;
    cout << obj.find(7) << endl; 

    return 0;
}