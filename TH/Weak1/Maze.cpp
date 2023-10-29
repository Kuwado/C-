#include <bits/stdc++.h> 
using namespace std; 

struct Block {
	int row, col, step;
}; 

int bestway(vector< vector<int> > maze, int n, int m, int r, int c){
	int dr[] = {-1, 0, 1, 0};
	int dc[] = {0, 1, 0, -1};
	
	queue<Block> q; // khoi tao hang doi Block
	q.push({r, c, 0}); // cat vi tri xuat phat vao hang doi
	maze[r][c] = 1; // gia tri cua o vi tri = 1 de khong bi xet lai
	
	while(!q.empty()){
		Block curBlock = q.front(); // lay Block dau tien o hang doi de xet
		q.pop(); // va xoa Block ay di
		if (curBlock.row == 0 || curBlock.row == n-1 || curBlock.col == 0 || curBlock.col == m-1){
			return curBlock.step + 1; // Neu Block ay thuoc cac o ngoai cung me cung thi can them 1 buoc de ra
		}
		for (int i = 0; i<4; i++){
				int newrow = curBlock.row + dr[i]; // xet lan luot 4 o xung quanh o hien tai
				int newcol = curBlock.col + dc[i]; // theo thu tu tren, phai, duoi, trai
				if (maze[newrow][newcol] == 0){
					q.push({newrow, newcol, curBlock.step+1}); // neu o day di duoc thi cat vao hang doi
					maze[newrow][newcol] = 1; // va dua gia tri ve 1 the hien viec da xet va khong duoc xet lai
				}		
			}
	}
	return -1; // neu ket thuc hang doi rong ma chua tim duoc dap an --> me cung khong loi thoat
}

int main() 
{ 
	int n,m,r,c;
	cin >> n >> m >> r >> c;
	vector< vector<int> > maze(n, vector<int>(m));
	if (1 <= n && n <= 999 && 1 <= m && m <= 999){
		for (int i = 0; i<n; i++){
			for (int j = 0; j<m; j++){
				cin >> maze[i][j]; // nhap gia tri ma tran me cung
			}	
		}
	}	
	int ans = bestway(maze, n, m, r-1, c-1);
	cout << ans << endl; // duong di ngan nhat
	
}

