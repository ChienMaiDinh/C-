#include <iostream>
#include <string>



using namespace std;


struct Student {
	int id;
	string name;
	float score;
};

void outPutInfor(Student *arrSd);			 //ham xuat thong tin 
void inPutInfor(int n,Student * arrSd);    	//ham nhap thong tin Student
void menu();								//ham in thong tin lua chon

int main(){
	Student * arrSd = new Student[100]; 	//khoi tao mang student
	
	return 0;
}
