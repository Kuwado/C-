#include <bits/stdc++.h> 
using namespace std;

// Hàm xây d?ng cây nh? phân
void build_tree(const vector<int>& arr, vector<int>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;

    build_tree(arr, tree, left_node, start, mid);
    build_tree(arr, tree, right_node, mid + 1, end);

    tree[node] = min(tree[left_node], tree[right_node]);
}

// Hàm truy v?n RMQ
int query(const vector<int>& tree, int node, int start, int end, int left, int right) {
    if (start > right || end < left) {
        return INT_MAX; // ?o?n con n?m ngoài ?o?n c?n truy v?n
    }

    if (start >= left && end <= right) {
        return tree[node]; // ?o?n con n?m hoàn toàn trong ?o?n c?n truy v?n
    }

    int mid = (start + end) / 2;
    int left_node = 2 * node + 1;
    int right_node = 2 * node + 2;

    int left_min = query(tree, left_node, start, mid, left, right);
    int right_min = query(tree, right_node, mid + 1, end, left, right);

    return min(left_min, right_min);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Tính chi?u cao c?a cây nh? phân
    int tree_height = ceil(log2(n));

    // S? l??ng nút trong cây nh? phân
    int tree_size = 2 * pow(2, tree_height) - 1;

    // Kh?i t?o cây nh? phân
    vector<int> segment_tree(tree_size, INT_MAX);
    build_tree(arr, segment_tree, 0, 0, n - 1);

    int m;
    cin >> m;
	int sum = 0;
    for (int i = 0; i < m; i++) {
        int b, c;
        cin >> b >> c;
        int result = query(segment_tree, 0, 0, n - 1, b, c);
        sum += result;
    }
	cout << sum << endl;
    return 0;
}

