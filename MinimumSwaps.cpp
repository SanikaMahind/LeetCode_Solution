#include <iostream>
#include <string>
using namespace std;

int minimumSwap(string s1, string s2) {
    int xy = 0;
    int yx = 0;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == 'x' && s2[i] == 'y')
            xy++;
        else if (s1[i] == 'y' && s2[i] == 'x')
            yx++;
    }

    if ((xy + yx) % 2 != 0)
        return -1;

    int swaps = xy / 2 + yx / 2;

   
    if (xy % 2 == 1 && yx % 2 == 1)
        swaps += 2;

    return swaps;
}

int main() {
    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    cout << "Minimum swaps = " << minimumSwap(s1, s2) << endl;

    return 0;
}