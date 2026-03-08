#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed)
{
    int n = position.size();
    vector<pair<int,double>> cars;

    for(int i = 0; i < n; i++)
    {
        double time = (double)(target - position[i]) / speed[i];
        cars.push_back({position[i], time});
    }

    sort(cars.begin(), cars.end());

    int fleets = 0;
    double prevTime = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(cars[i].second > prevTime)
        {
            fleets++;
            prevTime = cars[i].second;
        }
    }

    return fleets;
}

int main()
{
    int target = 12;
    vector<int> position = {10,8,0,5,3};
    vector<int> speed = {2,4,1,1,3};

    cout << "Number of fleets: " << carFleet(target, position, speed);

    return 0;
}