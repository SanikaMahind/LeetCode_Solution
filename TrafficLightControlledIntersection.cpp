#include <iostream>
#include <functional>
using namespace std;

class TrafficLight {
public:
    void carArrived(
        int carId,
        int roadId,
        int direction,
        function<void()> turnGreen,
        function<void()> crossCar
    ) {
       
        turnGreen();

      
        crossCar();
    }
};

int main() {
    TrafficLight trafficLight;

    
    trafficLight.carArrived(
        1, 1, 2,
        []() {
            cout << "Traffic light turned GREEN" << endl;
        },
        []() {
            cout << "Car crossed the intersection" << endl;
        }
    );

    return 0;
}