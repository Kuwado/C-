#include <iostream>
#include <vector>

using namespace std;

// Hàm ð? quy ð? ð?m s? lý?ng nghi?m
int countSolutions(int n, int M, const vector<int>& a, vector<int>& x, int currentSum, int currentIndex) {
    if (currentSum == M) {
        return 1; // T?m th?y m?t nghi?m
    }

    if (currentSum > M || currentIndex == n) {
        return 0; // Quá M ho?c ð? duy?t h?t các s? a
    }

    int result = 0;

    // Th? t?t c? các giá tr? có th? c?a x[currentIndex]
    for (int i = 1; i <= M; ++i) {
        x[currentIndex] = i;
        result += countSolutions(n, M, a, x, currentSum + a[currentIndex] * i, currentIndex + 1);
    }

    return result;
}

int main() {
    int n, M;
    cin >> n >> M;

    vector<int> a(n);
    vector<int> x(n, 0);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int result = countSolutions(n, M, a, x, 0, 0);
    cout << result << endl;

    return 0;
}

