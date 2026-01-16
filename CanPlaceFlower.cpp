#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int sz = flowerbed.size();

        for (int i = 0; i < sz; i++)
        {
            if (flowerbed[i] == 0)
            {
                bool left = (i == 0 || flowerbed[i - 1] == 0);
                bool right = (i == sz - 1 || flowerbed[i + 1] == 0);

                if (left && right)
                {
                    flowerbed[i] = 1;
                    n--;
                }
            }
        }

        return (n <= 0);
    }
};

int main()
{
    Solution obj;

    int size, n;
    cout << "Enter size of flowerbed: ";
    cin >> size;

    vector<int> flowerbed(size);
    cout << "Enter elements (0 or 1): ";
    for (int i = 0; i < size; i++)
    {
        cin >> flowerbed[i];
    }

    cout << "Enter number of flowers to place: ";
    cin >> n;

    if (obj.canPlaceFlowers(flowerbed, n))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
