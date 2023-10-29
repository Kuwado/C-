#include <bits/stdc++.h> 
using namespace std; 

typedef struct node{
	string name;
	string bd;
	string cl;
	struct node *next;
} NODE;	// tao cac node

typedef struct list{
	NODE* head;
	NODE* tail;
}LIST; // tao danh sach

void taodanhsach(LIST l){
	l.head = l.tail = NULL;
} // khoi tao diem dau va diem cuoi danh sach

NODE *nhapnut(){ 
	NODE *p = new NODE; // cap phat bo nho
	if (p == NULL)
		return NULL; // neu cap phat khong thanh cong --> NULL
	else {
		cout << "Nhap ten:" << endl;
		getline(cin, p->name);
		cout << "Nhap ngay sinh:" << endl;
		getline(cin, p->bd);
		cout << "Nhap lop:" << endl;
		getline(cin, p->cl);
		p->next = NULL; 
	}
	return p; // neu cap phat thanh cong tro toi nut moi
}

void themdau(LIST &l, NODE* p){
	if (l.head == NULL){
		l.head = p;
		p->next = NULL;
	}
	else {
		p->next = l.head;
		l.head = p;
	}
}

void nhapdanhsach(LIST &l, int n){
	taodanhsach(l);
	for (int i = 1; i <= n; i++){
		themdau(l,p); 
	}	
} 

void indanhsach(LIST l){
	NODE* p = l.head;
	cout <<left << setw(5) << "STT";
	cout << setw(20) << "Ten sinh vien"; 
	cout << setw(12) << "Ngay sinh";
	cout << setw(10) << "Lop";
	cout << "\n" << endl;
	for(int i = 1; p != NULL; i++){
		cout << setw(5) << i;
		cout << setw(20) << p->name; 
		cout << setw(12) << p->bd;
		cout << setw(10) << p->cl;
		cout << "\n" << endl;
		p=p->next;
	}
}









int main(){
	int c, n;
	LIST danhsach;
		do {
		cin >> c;
		switch (c)
		{
			case 1: // them phan tu dau
				int n;
				cin >> n;
				cin.ignore();
				nhapdanhsach(danhsach, n);
				indanhsach(danhsach);
				break;
			case 2:
				cout<< "h" << endl;
		        break;
		    case 5:
		    	break;
	} }while (c!=6);
	return 0;
}


