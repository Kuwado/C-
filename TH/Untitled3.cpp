#include <bits/stdc++.h>
using namespace std;

int n,k,c[23][23],d[23],dem = 0,_min = 1e9;
int res = 1e9,s = 0,t;

void Try(int x,int y) { // ham de quy thu cach sap xep va cap nhat ket qua toi uu 
    if (dem < k)
    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            dem++;
            d[i] = 1;
            s += c[y][i];
            // tiep tuc thu neu khong vuot qua gioi han
            if(s + (t-x)*_min < res) Try(x+1,i);
            s -= c[y][i];
            d[i] = 0;
            dem--;
        }
    }
    for (int i = n+1; i < t; i++) {
        if (!d[i] && d[i-n]) {
            dem--;
            d[i] = 1;
            s += c[y][i];
            // neu da duyet het tat ca cac diem, cap nhat ket qua toi uu
            if (x == t - 1) {
                res = min(res,s+c[i][0]);
            }
            // tiep tuc thu 
            if (s + (t-x)*_min < res) Try(x+1,i);
            s -= c[y][i];
            d[i] = 0;
            dem++;
        }
    }
}

int main() {
    cin >> n >> k;
    t = (n << 1)+1;
    for (int i = 0; i < t; i++)
        for (int j = 0; j < t; j++) {
            cin >> c[i][j];
           if(i != j) _min = min(_min,c[i][j]);
        }
    Try(1,0);
    cout << res;
}
