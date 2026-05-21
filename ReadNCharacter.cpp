#include <iostream>
using namespace std;

string fileData = "HelloWorld";
int filePointer = 0;

int read4(char *buf4) {
    int i = 0;

    while (i < 4 && filePointer < fileData.size()) {
        buf4[i] = fileData[filePointer];
        i++;
        filePointer++;
    }

    return i;
}

class Solution {
public:
    int read(char *buf, int n) {
        int total = 0;
        char temp[4];

        while (total < n) {
            int count = read4(temp);

           
            if (count == 0)
                break;

            for (int i = 0; i < count && total < n; i++) {
                buf[total] = temp[i];
                total++;
            }
        }

        return total;
    }
};

int main() {
    Solution obj;

    char buf[100];
    int n;

    cout << "Enter number of characters to read: ";
    cin >> n;

    int charactersRead = obj.read(buf, n);

    cout << "Characters read: " << charactersRead << endl;

    cout << "Output: ";
    for (int i = 0; i < charactersRead; i++) {
        cout << buf[i];
    }

    cout << endl;

    return 0;
}