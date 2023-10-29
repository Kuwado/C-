//C++ 
#include <bits/stdc++.h> 
using namespace std;

#define M 1000000

int check(int start, int end){
	int n = (end - start - 1);
	if(n%2 == 0) return 1;
	else return 0;
	
}

int main() { 
    char line[M];
	cin >> line;
	stack<int> tron, vuong, nhon;
	int ans = 1;
	for (int i = 0; line[i] != 0; i++){
		char c = line[i];
		switch(c){
			case '(' :
				tron.push(i);
				break;
				
			case '[' :
				vuong.push(i);
				break;
				
			case '{' :
				nhon.push(i);
				break;
			
			case ')' :
				if (!tron.empty()){
					ans = check(tron.top(), i);
					tron.pop();
				}
				else 
					ans = 0;
					break;
				
			case ']' :
				if (!vuong.empty()){
					ans = check(vuong.top(), i);
					vuong.pop();
				}
				else 
					ans = 0;
					break;
				
			case '}' :
				if (!nhon.empty()){
					ans = check(nhon.top(), i);
					nhon.pop();
				}
				else 
					ans = 0;
					break;
		}
		
	if (ans == 0) break;
	}
	
	if (!tron.empty()) ans = 0; 
	if (!vuong.empty()) ans = 0; 
	if (!nhon.empty()) ans = 0; 
	cout << ans << endl;
}
