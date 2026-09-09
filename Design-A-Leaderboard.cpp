#include <bits/stdc++.h>
using namespace std;

class Leaderboard {
private:
    unordered_map<int, int> score;

public:
    Leaderboard() {
    }

    void addScore(int playerId, int Score) {
        score[playerId] += Score;
    }

    int top(int K) {
        vector<int> scores;

        for (auto &p : score) {
            scores.push_back(p.second);
        }

        sort(scores.rbegin(), scores.rend());

        int sum = 0;

        for (int i = 0; i < K && i < scores.size(); i++) {
            sum += scores[i];
        }

        return sum;
    }

    void reset(int playerId) {
        score[playerId] = 0;
    }
};

int main() {
    Leaderboard leaderboard;

    leaderboard.addScore(1, 73);
    leaderboard.addScore(2, 56);
    leaderboard.addScore(3, 39);
    leaderboard.addScore(4, 51);
    leaderboard.addScore(5, 4);

    cout << "Top 1: " << leaderboard.top(1) << endl;
    cout << "Top 3: " << leaderboard.top(3) << endl;

    leaderboard.reset(1);

    cout << "After resetting player 1:" << endl;
    cout << "Top 3: " << leaderboard.top(3) << endl;

    leaderboard.addScore(2, 10);

    cout << "After adding 10 points to player 2:" << endl;
    cout << "Top 3: " << leaderboard.top(3) << endl;

    return 0;
}