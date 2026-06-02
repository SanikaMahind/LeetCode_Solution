#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    unordered_map<string, multiset<string>> graph;
    vector<string> itinerary;

    void dfs(string airport) {
        while (!graph[airport].empty()) {
            auto next = graph[airport].begin();
            string dest = *next;
            graph[airport].erase(next);
            dfs(dest);
        }
        itinerary.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto &ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK");

        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};

int main() {
    Solution sol;

    vector<vector<string>> tickets = {
        {"MUC", "LHR"},
        {"JFK", "MUC"},
        {"SFO", "SJC"},
        {"LHR", "SFO"}
    };

    vector<string> result = sol.findItinerary(tickets);

    cout << "Itinerary: ";
    for (string airport : result) {
        cout << airport << " ";
    }
    cout << endl;

    return 0;
}