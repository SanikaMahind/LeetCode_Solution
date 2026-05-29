#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {

    vector<string> customers = {"Joe", "Henry", "Sam", "Max"};

    vector<string> orders = {"Henry", "Sam"};

    set<string> orderedCustomers;

    for (string name : orders) {
        orderedCustomers.insert(name);
    }

    cout << "Customers Who Never Order:" << endl;

 
    for (string customer : customers) {

        if (orderedCustomers.find(customer) ==
            orderedCustomers.end()) {

            cout << customer << endl;
        }
    }

    return 0;
}