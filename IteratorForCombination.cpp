#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CombinationIterator {
private:
    vector<string> combinations;
    int idx;

    void generate(string &characters, int length, int start, string current) {
        if (current.size() == length) {
            combinations.push_back(current);
            return;
        }

        for (int i = start; i < characters.size(); i++) {
            generate(characters, length, i + 1, current + characters[i]);
        }
    }

public:
    CombinationIterator(string characters, int combinationLength) {
        idx = 0;
        generate(characters, combinationLength, 0, "");
    }

    string next() {
        return combinations[idx++];
    }

    bool hasNext() {
        return idx < combinations.size();
    }
};

int main() {
    CombinationIterator iterator("abc", 2);

    cout << iterator.next() << endl;    
    cout << iterator.hasNext() << endl;  
    cout << iterator.next() << endl;     
    cout << iterator.hasNext() << endl; 
    cout << iterator.next() << endl;     
    cout << iterator.hasNext() << endl;  

    return 0;
}