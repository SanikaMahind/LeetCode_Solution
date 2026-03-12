#include <iostream>
using namespace std;

double myPow(double x, int n) 
{
    long long power = n;
    
    if(power < 0)
    {
        x = 1 / x;
        power = -power;
    }

    double result = 1;

    while(power > 0)
    {
        if(power % 2 == 1)
        {
            result = result * x;
        }

        x = x * x;
        power = power / 2;
    }

    return result;
}

int main()
{
    double x = 2;
    int n = 10;

    cout << "Result: " << myPow(x, n) << endl;

    return 0;
}