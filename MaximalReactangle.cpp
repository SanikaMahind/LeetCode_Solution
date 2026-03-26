#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;
    heights.push_back(0); 

    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * width);
        }
        st.push(i);
    }

    heights.pop_back();
    return maxArea;
}


int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;

    int n = matrix[0].size();
    vector<int> heights(n, 0);
    int maxArea = 0;

    for (auto& row : matrix) {
        for (int i = 0; i < n; i++) {
            if (row[i] == '1')
                heights[i] += 1;
            else
                heights[i] = 0;
        }

        maxArea = max(maxArea, largestRectangleArea(heights));
    }

    return maxArea;
}

int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    cout << "Max Rectangle Area: " << maximalRectangle(matrix);

    return 0;
}