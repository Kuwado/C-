#include <bits/stdc++.h> 
using namespace std;

// Ham tinh dien tich lon nhat trong histogram
int largestRectangleArea(const vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;

    for (int i = 0; i < heights.size(); ++i) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int height = heights[s.top()]; 
            s.pop();
            int width = s.empty() ? i : i - s.top() - 1; // neu stack rong thi chieu dai la i 
            maxArea = max(maxArea, height * width); 
        }
        s.push(i);
    }

    while (!s.empty()) {
        int height = heights[s.top()];
        s.pop();
        int width = s.empty() ? heights.size() : heights.size() - s.top() - 1;
        maxArea = max(maxArea, height * width);
    }

    return maxArea;
}

// ham tinh dien tich lon nhat trong ma tran
int largestRectangleInMatrix(const vector<vector<int> >& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> histogram(m, 0);
    int maxRectangle = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Neu la o den thi cong them 1
            if (matrix[i][j] == 1) {
                histogram[j]++;
            }
            // Neu la trang thi reset ve 0
            else {
                histogram[j] = 0;
            }
        }

        // Tim dien tich lon nhat trong hang i
        maxRectangle = max(maxRectangle, largestRectangleArea(histogram));
    }

    return maxRectangle;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > matrix(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int result = largestRectangleInMatrix(matrix); // tim dien tich lon nhat

    cout << result << endl; // i ket qua

    return 0;
}

