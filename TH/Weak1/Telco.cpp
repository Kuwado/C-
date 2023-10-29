#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

struct In4{
	string fnum, tnum, date, ftime, etime;
};

struct Quest{
	string option, phone;
};

unordered_map <string, int> callcount;
unordered_map <string, int> timecount;
 
int check(string phone){
	for (int i = 0; i < phone.length(); i++){
		char c = phone[i]; // kiem tra tung phan tu trong so dien thoai 
		if(!isdigit(c)) return 0; // neu co mot ky tu khong phai so --> 0
	} 
	return 1; // neu toan bo la chu so --> 1
}

int main(){
	vector<In4> Call;
	vector<Quest> Quests;
	string data;
	string quest;
	int ans = 1; 

	while(getline(cin, data)){
		if (data == "#"){
			break; // nap du lieu den khi gap # thi ngat
		}
		istringstream iss(data); // doc du lieu tu chuoi
		In4 newCall;
		iss >> data >> newCall.fnum >> newCall.tnum >> newCall.date >> newCall.ftime >> newCall.etime; // nap du lieu
		if (check(newCall.fnum) == 1 && check(newCall.tnum) == 1){ // neu khong co so dien thoai nao loi
			Call.push_back(newCall); // nap vao vector
			callcount[newCall.fnum] ++; // tang so cuoc goi den tu fnum len 1
			timecount[newCall.fnum] += 3600* (10* (newCall.etime[0] - newCall.ftime[0]) + newCall.etime[1] - newCall.ftime[1]) + 60* (10* (newCall.etime[3] - newCall.ftime[3]) + newCall.etime[4] - newCall.ftime[4]) + 10* (newCall.etime[6] - newCall.ftime[6]) + newCall.etime[7] - newCall.ftime[7];// tinh tong thoi gian goi
		}
		else 
			ans = 0; // neu co it nhat mot so dien thoai loi tra ve 0
		
	}
	while(getline(cin, quest)){
		if (quest == "#"){
			break;
		}
		Quest newquest;
		istringstream iss(quest);
		iss >> newquest.option >> newquest.phone;
		Quests.push_back(newquest);
	}
	
	for (int i = 0; i < Quests.size(); i++){
		if (Quests[i].option == "?check_phone_number"){
			cout << ans << endl; // kiem tra xem co so dien thoai nao loi khong
		}
		if (Quests[i].option == "?number_calls_from"){
			cout << callcount[Quests[i].phone] << endl; // dem so cuoc goi tu so dien thoai fnum
		}
		if (Quests[i].option == "?number_total_calls"){
			cout << Call.size() << endl; // dem tong so cuoc goi duoc thuc hien
		}
		if (Quests[i].option == "?count_time_calls_from"){
			cout << timecount[Quests[i].phone] << endl; // tinh tong thoi gian duoc thuc hien boi so dien thoai fnum
		}
	}	
}
	
