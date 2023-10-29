#include <bits/stdc++.h> 
using namespace std;

// ham thiet lap cay phan doan 
void build_tree(const vector<int>& arr, vector<int>& tree, int node, int start, int end){
	if (start == end){ // nut la
		tree[node] = arr[start];
		return;
	}
	
	int mid = (start + end)/2; 
	int left_node = 2*node + 1; // nut con trai
	int right_node = 2*node + 2; // nut con phai
	// de quy thiet lap tiep cac nut con 
	build_tree(arr, tree, left_node, start, mid); 
	build_tree(arr, tree, right_node, mid+1, end);
	// nut trong la min cua 2 nut con
	tree[node] = min(tree[left_node], tree[right_node]);
} 

// ham tim nut be nhat
int find_min(const vector<int>& tree, int node, int start, int end, int left, int right){
	if (start > right || end < left){
		return INT_MAX; // neu khoang dang xet nam ngoai khoang yeu cau gan gia tri la so nguyen lon nhat
	} // va khong can xet tiep cac nut con trong khoang nay
	
	if (start >= left && end <= right){
		return tree[node]; // neu khoang dang xet nam trong khoang yeu cau thi nut nay la min
	}
	
	int mid = (start + end)/2;
	int left_node = 2*node + 1;
	int right_node = 2*node + 2;
	
	int minl = find_min(tree, left_node, start, mid, left, right); // tim min cua nut ben trai
	int minr = find_min(tree, right_node, mid+1, end, left, right); // tim min cua nut ben phai
	return min(minl, minr); // min cuoi cung la min nho nhat cua cac min 
}

int main(){
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for (int i = 0; i<n; i++){
		cin >> arr[i];
	}
	
	int tree_height = ceil(log2(n)); // chieu cao cay la so nguyen gan nhat >= log2(n)
	int tree_size = 2 * pow(2, tree_height) - 1; // so luong phan tu cay = 2^n - 1
	vector<int> tree(tree_size); // khoi tao va thiet lap cay
	build_tree(arr, tree, 0, 0, n-1);
	
	int m;
	cin >> m;
	int sum = 0;
	for (int i = 0; i < m; i++){
		int l, r;
		cin >> l >> r;
		sum += find_min(tree, 0, 0, n-1, l, r); // tinh tong cac min 
	}
		cout << sum << endl;
} 
