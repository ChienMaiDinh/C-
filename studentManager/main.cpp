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
int inputId(int i,Student* arrSd);   		// ham check ID trung
float inputScore(); 						//ham check diem < 0 va >10



float inputScore(){
	float sCore;
	bool check=true;
	while(check){
		cout<<" Score student :"<<endl;
		cin>>sCore;
		check=false;
		if(sCore>10 ||sCore<0){
			check=true;
			cout<<"input sCore wrong, please input valid , ";
		}
	}
	return sCore;
};

int inputId(int i,Student* arrSd){
	int id;
	bool check=true;
	while(check){
		cout<<" id student :"<<endl;
		cin>>id;
		check=false;
		for(int j=0;j<i;j++){
			if(id==arrSd[j].id){
			cout<<" id is exist, please input new id, ";
			check=true;
			}
		}
	}
	return id;
};


void inPutInfor(int n,Student * arrSd) {
	Student temp;
	for(int i=0 ; i<n;i++){
		cout<<"fill information student "<<i+1<<endl;
		cout<< "fill ID student :"<<endl;
		temp.id = inputId(i,arrSd);
		cout<<" Name student :"<<endl;
		getline(cin,temp.name);
		cout<< "fill score student :"<<endl;
		temp.score= inputScore();
		arrSd[i]=temp;
	}
}

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
	int choose;
	do{
		menu();
		cin>>choose;
		switch (choose)
		{
		case 1 :
			int n;
			cout<<"input number Student  : "<<endl;
			cin>>n;
			inPutInfor(n,arrSd);
			break;
		case 2 :
			outPutInfor(arrSd);
			break;
		case 3 :
			break;
		case 4 :
			break;
		case 0 :
			break;
		}
	}while(choose!=0);
	return 0;
}
