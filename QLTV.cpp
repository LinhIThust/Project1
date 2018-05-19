#include <bits/stdc++.h>
#define MAXN 300
#define MAXName 34
#define F(i,a,b) for(int i =a;i<=b;i++)
//----------------------------------------//
using namespace std;
int num=0;

struct members{
	int  ID;
	char name[MAXName];
	int age;
	int groupID;
};

members member[MAXN];
//
//void addFile(){
//	fprintf(f,"thanh vien thu %d :\n",num);
//	fprintf(f,"%d\n",member[num].groupID);
//	fprintf(f,"%d\n",member[num].ID);
//	fprintf(f,"%d\n",member[num].age);
//	fprintf(f,"%s\n",member[num].name);
//}

int findMember(int id){
	for(int i =1;i<=num;i++){
		if(member[i].ID == id)
			return i;
	}
}

bool checkID(int id){
	for(int i = 1; i<=num;i++)
		if(member[i].ID == id)
			return false;
 	return true;
}

void addMenber(){
	cout<<"NOTE: nhan -1 de ngung nhap!!"<<endl;
	while(1){
		int id;
		num++;
		while(1){
			cout<<"Nhap ID:";
			cin >>id;
			if(id == -1){
				num--;
				return;
			}
			if(!checkID(id)){
				cout<<"ID ban vua nhap vua bi trung!Hay nhap lai:"<<endl;
			} else{
				member[num].ID = id;
				break;
			}
		}
		cout<<"Nhap tuoi:";
		cin >>member[num].age;
		cout<<"Nhap nhom:";
		cin >>member[num].groupID;
		cout<<"Nhap ten:";
		fflush(stdin);
		gets(member[num].name);
	}
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
	for(int j = i+1 ;j<=num;j++){
		member[j-1] = member[j];
	}
	num--;
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

void printAllMember(){
	cout<<"so thanh vien trong Doi la:"<<num<<endl;
	printf("ID              NAME               AGE    GROUP");
	printf("\n");
	for(int i =1;i<=num;i++){
	printf("%6d%25s%6d%6d\n",member[i].ID,member[i].name,member[i].age,member[i].groupID);
	}
}

void Quick_sort(int L,int R){
	int i,j,pivot;
	i = L;
	j = R;
	pivot = member[L+rand()%(R-L+1)].ID;
	do{
		while(member[i].ID<pivot) i++;
		while(member[j].ID>pivot) j--;
		if(i<=j){
			swap(member[i],member[j]);
			i++;j--;
		}
	}while( i<=j);
	if(i<R) Quick_sort(i,R);
	if(j>L) Quick_sort(L,j);
}

void SapXepID(){
	cout<<"danh sach Thanh vien Theo ID tang dan!"<<endl;
	Quick_sort(1,num);
	printAllMember();
 }

void Menu(){
	cout<<"||---------------------------------------------||"<<endl;
	cout<<"||>>>>>>>>>HE THONG QUAN LI THANH VIEN<<<<<<<<<||"<<endl;
	cout<<"||     Them thanh vien moi         : 1         || "<<endl;
	cout<<"||     Xoa thanh vien cu           : 2         ||"<<endl;
	cout<<"||     Sua thong tin thanh vien    : 3         ||"<<endl;
	cout<<"||     In thanh vien Doi theo ID   : 4         ||"<<endl;
	cout<<"||     In tat ca thanh vien Doi    : 5         ||"<<endl;
	cout<<"||     Sap xep thanh vien theo ID  : 6         ||"<<endl;
	cout<<"||---------------------------------------------||"<<endl;
	cout<<"   ==> Nhan de chon chuc nang   : ";
	int option;
	cin>>option;
	switch(option){
		case 1 : addMenber(); break;
		case 2 : deleteMember(); break;
		case 3 : editMember(); break;
		case 4 : printMember();break;
		case 5 : printAllMember();break;
		case 6 : SapXepID();break;
		default: cout<<"Vui long nhap lai!"<<endl;
	}
}

int main(){
	printf ("cc");
	char. ch;
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
