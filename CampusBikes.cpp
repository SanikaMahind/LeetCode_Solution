#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    vector<vector<int>> workers = {{0, 0}, {2, 1}};
    vector<vector<int>> bikes = {{1, 2}, {3, 3}};

    vector<vector<int>> all;

    
    for (int i = 0; i < workers.size(); i++) {
        for (int j = 0; j < bikes.size(); j++) {
            int dist = abs(workers[i][0] - bikes[j][0]) +
                       abs(workers[i][1] - bikes[j][1]);
            all.push_back({dist, i, j});
        }
    }

    sort(all.begin(), all.end());

    vector<int> ans(workers.size(), -1);
    vector<bool> usedBike(bikes.size(), false);

    for (auto x : all) {
        int worker = x[1];
        int bike = x[2];

        if (ans[worker] == -1 && !usedBike[bike]) {
            ans[worker] = bike;
            usedBike[bike] = true;
        }
    }

    cout << "Assigned Bikes: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;

    return 0;
}