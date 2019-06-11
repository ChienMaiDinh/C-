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

void menu() {
	
	cout << "-------------------MENU-------------------\n";
	cout << "		1.		input \n";
	cout << "		2.		Display \n";
	cout << "		3.		Save to file \n";
	cout << "		4.		Load from file \n";
	cout << "		0.		Exit \n";
	cout << "-----------------------------------------\n";
	cout << "Choose : \n";

}

int main(){
	Student * arrSd = new Student[100]; 	//khoi tao mang student
	
	return 0;
}
