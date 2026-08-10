#include <iostream>
#include <vector>
using namespace std;

vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    vector<int> ans;

   
    if (tomatoSlices % 2 != 0)
        return ans;

    int jumbo = (tomatoSlices - 2 * cheeseSlices) / 2;
    int small = cheeseSlices - jumbo;

   
    if (jumbo < 0 || small < 0)
        return ans;

    
    if (4 * jumbo + 2 * small != tomatoSlices)
        return ans;

    ans.push_back(jumbo);
    ans.push_back(small);

    return ans;
}

int main() {
    int tomatoSlices, cheeseSlices;

    cin >> tomatoSlices >> cheeseSlices;

    vector<int> result = numOfBurgers(tomatoSlices, cheeseSlices);

    if (result.empty()) {
        cout << "No solution";
    } else {
        cout << "[" << result[0] << ", " << result[1] << "]";
    }

    return 0;
}