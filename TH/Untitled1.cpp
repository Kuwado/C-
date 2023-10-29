#include <bits/stdc++.h> 
using namespace std; 
#define maxN 50
vector<int> T[maxN]; 
int m, n; 
bool conflict[maxN][maxN]; 
int x[maxN]; 
int load[maxN]; 
int res; 

void input(){
    cin >> m >> n; // Nhap so luong phong va so luong mon  
    for(int t=1; t<=m; t++){
        int k;
        cin >> k; // Nhap so luong phong ma mon co the xep vao  
        for (int j=1; j<=k; j++)
        {
            int c;
            cin >> c; 
            T[c].push_back(t); // Them thong tin ve mon vao danh sach  
        }
    }
    int K;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            conflict[i][j] = false; // Khoi tao mang xung dot  
        }
    }
    cin >> K; 
    for(int k=1; k<=K; k++){
        int i, j;
        cin >> i >> j;
        conflict[i][j] = true; // danh dau xung dot giua mon i và j
        conflict[j][i] = true; // dam bao xung dot la doi xung  
    }
}

bool check(int t, int k){
    for(int i=1; i<=k-1; i++){
        if(conflict[i][k] && x[i] == t) return false; // kiem tra xung dot  
    }
    return true;
}

void solution(){
    int maxLoad = 0;
    for(int t=1; t<=m; t++){
        maxLoad = max(maxLoad, load[t]); // Tim so luong mon nhieu nhat da duoc xep  
    }
    if(maxLoad < res) res = maxLoad; // Cap nhat neu co gp tot hon 
}

void Try(int k){
    for(int i=0; i<T[k].size(); i++){
        int t = T[k][i];
        if(check(t,k)){
            x[k] = t; // gan gia tri tam thoi cho mon k  
            load[t] += 1; // Tang so luong mon da duoc xep vao phong t
            if(k == n) solution(); // neu het mon --> cap nhat  
            else{
                if(load[t] < res) Try(k+1); // Goi de quy  
            }
            load[t] -= 1; // quay lai truoc do  
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input(); // nhap input  
    for(int i = 1; i <= m; i++){
        load[i] = 0;
    }
    res = 1e9; // khoi tao ket qua la mot gia tri lon  
    Try(1); 
    cout << res << endl; 
    return 0;
}

