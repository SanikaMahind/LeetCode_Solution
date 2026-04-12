#include <iostream>
#include <vector>
#include <set>

using namespace std;

int getNthHighestSalary(vector<int>& salary, int N) {
    
    set<int, greater<int>> s(salary.begin(), salary.end());

    if (N > s.size()) {
        return -1; 
    }

    auto it = s.begin();
    advance(it, N - 1);

    return *it;
}

int main() {
    int n, N;

    cout << "Enter number of employees: ";
    cin >> n;

    vector<int> salary(n);

    cout << "Enter salaries:\n";
    for (int i = 0; i < n; i++) {
        cin >> salary[i];
    }

    cout << "Enter N (Nth highest salary to find): ";
    cin >> N;

    int result = getNthHighestSalary(salary, N);

    if (result == -1)
        cout << "Result: NULL (Not enough unique salaries)\n";
    else
        cout << "Nth Highest Salary: " << result << endl;

    return 0;
}