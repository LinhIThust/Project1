#include <bits/stdc++.h>
#define MAXN 300
#define MAXName 34
#define F(i,a,b) for(int i =a;i<=b;i++)

using namespace std;
int num=0;
struct members{
	int  ID;
	char name[MAXName];
	int age;
	int groupID;
};

FILE*f = fopen("output.txt","a+");

members member[MAXN];

void addFile(){
	fprintf(f,"thanh vien thu %d :\n",num);
	fprintf(f,"%d\n",member[num].groupID);
	fprintf(f,"%d\n",member[num].ID);
	fprintf(f,"%d\n",member[num].age);
	fprintf(f,"%s\n",member[num].name);
}

int findMember(int id){
	for(int i =1;i<=num;i++){
		if(member[i].ID == id)
			return i;
	}
}

void addMenber(){
	cout<<"NOTE: nhan 1 de ngung nhap!!"<<endl;
	while(1){
		num++;
		cout<<"Nhap ID:";
		cin >>member[num].ID ;
		if(member[num].ID == -1){
			num--;
			break;
		}
		cout<<"Nhap tuoi:";
		cin >>member[num].age;
		cout<<"Nhap nhom:";
		cin >>member[num].groupID;
		cout<<"Nhap ten:";
		fflush(stdin);
		gets(member[num].name);
		addFile();
	}
}

void printMember(){
	int id;
	cout<<"Nhap ID:";
	cin>> id;
	int i = findMember(id);
	cout<<"============================="<<endl;
	cout<<"ID  :" <<member[i].ID << endl;
	cout<<"Ten :" <<member[i].name << endl;
 	cout<<"Tuoi:" <<member[i].age << endl;
 	cout<<"Nhom:" <<member[i].groupID <<endl;
}

void deleteMember(){
	int id;
	cout<<"Nhap ID:";
	cin>> id;
	int i = findMember(id);
	if( i==0){
		cout<<"thanh vien khong ton tai!"<<endl;
		return;
	}
	member[i].ID =-1;
	//member[i].name=32;
	member[i].age =0;
	member[i].groupID=0;
}

void editMember(){
	int id;
	cout<<"Nhap ID:";
	cin>> id;
	int i = findMember(id);
	if( i==0){
		cout<<"thanh vien khong ton tai!"<<endl;
		return;
	}
	cout<<"Cap nhat thong tin"<<endl;
	cout<<"ID:" ;cin>>member[i].ID;
	cout<<"Ten:" ;cin>>member[i].name;
	cout<<"Tuoi:" ;cin>>member[i].age;
	cout<<"Nhom:" ;cin>>member[i].groupID;

}

void Menu(){
	cout<<"||------------------------------------------||"<<endl;
	cout<<"||>>>>>>>HE THONG QUAN LI THANH VIEN<<<<<<<<||"<<endl;
	cout<<"||     Them thanh vien moi      : 1         || "<<endl;
	cout<<"||     Xoa thanh vien cu        : 2         ||"<<endl;
	cout<<"||     Sua thong tin thanh vien : 3         ||"<<endl;
	cout<<"||     In thanh vien Doi theo ID: 4         ||"<<endl;
	cout<<"||------------------------------------------||"<<endl;
	cout<<"   ==> Nhan de chon chuc nang   : ";
	int option;
	cin>>option;
	switch(option){
		case 1 : addMenber(); break;
		case 2 : deleteMember; break;
		case 3 : editMember(); break;
		case 4 : printMember();break;
		default: cout<<"Vui long nhap lai!"<<endl;
	}

}


int main(){
	char ch;
	do{
		Menu();
		cout<<"Ban muon tiep tuc hay thoat(Y/N):";
		cin>>ch;
		system("cls");

	}while( ch =='Y'||ch =='y');

	cout<<"Cam on ban da su dung ung dung"<<endl;
	cout<<"----Copyright :Linhdzai--------";
	return 0;

}