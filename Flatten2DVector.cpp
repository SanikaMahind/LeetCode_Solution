#include <iostream>
#include <vector>
using namespace std;

class Vector2D {
private:
    vector<vector<int>> vec;
    int i, j;  

public:
    Vector2D(vector<vector<int>>& v) {
        vec = v;
        i = 0;
        j = 0;
    }

    int next() {
        return vec[i][j++];
    }

    bool hasNext() {
        
        while (i < vec.size() && j >= vec[i].size()) {
            i++;
            j = 0;
        }
        return i < vec.size();
    }
};

int main() {
    vector<vector<int>> v = {{1, 2}, {3}, {4, 5, 6}};

    Vector2D obj(v);

    cout << "Flattened Vector: ";
    while (obj.hasNext()) {
        cout << obj.next() << " ";
    }

    return 0;
}