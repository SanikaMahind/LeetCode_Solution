#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    
    vector<int> scores = {100, 90, 90, 80, 75, 60};

    set<int, greater<int>> uniqueScores(scores.begin(), scores.end());

    
    map<int, int> rankMap;
    int rank = 1;
    for (int score : uniqueScores) {
        rankMap[score] = rank++;
    }

    cout << "Score\tRank\n";
    for (int score : scores) {
        cout << score << "\t" << rankMap[score] << endl;
    }

    return 0;
}