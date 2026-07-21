#include <iostream>
#include <queue>
using namespace std;

class RecentCounter {
    queue<int> q;

public:
    int ping(int t) {
        q.push(t);

        while(q.front() < t - 3000)
            q.pop();

        return q.size();
    }
};

int main() {
    RecentCounter rc;

    cout << rc.ping(1) << endl;
    cout << rc.ping(100) << endl;
    cout << rc.ping(3001) << endl;
    cout << rc.ping(3002) << endl;

    return 0;
}