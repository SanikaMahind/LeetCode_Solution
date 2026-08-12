#include <iostream>
#include <vector>
using namespace std;

class Sea {
public:
    bool hasShips(vector<int> topRight, vector<int> bottomLeft) {
        
        return true;
    }
};

class Solution {
public:
    int countShips(Sea sea, vector<int> tr, vector<int> bl) {
        if (!sea.hasShips(tr, bl)) return 0;
        if (tr == bl) return 1;

        int x = (tr[0] + bl[0]) / 2;
        int y = (tr[1] + bl[1]) / 2;

        return countShips(sea, {x,y}, bl) +
               countShips(sea, tr, {x+1,y+1}) +
               countShips(sea, {x,tr[1]}, {bl[0],y+1}) +
               countShips(sea, {tr[0],y}, {x+1,bl[1]});
    }
};

int main() {
    Sea sea;
    Solution s;

    cout << s.countShips(sea, {4,4}, {0,0});
    return 0;
}