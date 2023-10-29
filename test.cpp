#include <bits/stdc++.h> 
#include <string>
using namespace std; 

int main() { 
	string s = "\n", c, res;
	for (int i=0; i<100000; i++){
		getline(cin, c) ;
		if (c == "*"){
			break; 	
		} 
		if (c.length()>0 && c.length()<51 ) {
				s += c + "\n";
		}
	}
	for (int i=0; i< 100000; i++){
		getline(cin, c) ;
		if (c == "***"){
			int m = res.length() - 1;
			res.erase(m,1);
			break; 
		} 
		if (c.find("find") == 0){
			string name = "\n" + c.erase(0,5) + "\n";
			if (s.find(name) == -1) 
				res += "0\n";
			else 
				res += "1\n";
			}
		if (c.find("insert") == 0){
			string name = c.erase(0,7);
			string name1 = "\n" + name + "\n";
			if (s.find(name1) == -1) {
				s += name + "\n";
				res += "1\n";
			}
			else
				res += "0\n"; 
		}
	}
	cout << res << endl;
}
