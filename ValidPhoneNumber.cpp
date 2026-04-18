#include <iostream>
#include <fstream>
#include <regex>
using namespace std;

int main() {
    ifstream file("file.txt");  
    string line;

    
    regex pattern(R"(^(\(\d{3}\) \d{3}-\d{4}|\d{3}-\d{3}-\d{4})$)");

    while (getline(file, line)) {
        if (regex_match(line, pattern)) {
            cout << line << endl;
        }
    }

    file.close();
    return 0;
}