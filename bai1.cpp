#include <bits/stdc++.h> 
#include <string>
using namespace std; 

string searchstr(string& s, string& name){
	name = "\n" + name + "\n";
	if (s.find(name) == -1) 
		return "0";
	else
		return "1"; 
} 

string insertstr(string& s, string& name){
	string name1 = "\n" + name + "\n";
	if (s.find(name1) == -1) {
		s += name + "\n";
		return "1";}
	else
		return "0"; 
}

int main() { 
	string s = "\n", c, a; 
	string res;
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
				string name = c.erase(0,5);
				string n = searchstr(s, name);
				res += n + "\n";
			}
		if (c.find("insert") == 0){
				string name = c.erase(0,7);
				string n = insertstr(s, name);
				res += n + "\n";
			}	
	}
	cout << res << endl;
}
