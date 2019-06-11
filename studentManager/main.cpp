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
int countArray=0; 							//bien cam canh giu chi so vi tri con tro Student dang tro toi
void saveToFile(Student* arrSd); 			// ham luu mang da nhap vao file
void loadFromFile();						//ham load thong tin tu file ra


void saveToFile(Student* arrSd){
	ofstream fileOut;
	fileOut.open("Student.txt",std::ios_base::out);
	if(fileOut.is_open()){
		//save number Student
		fileOut<<countArray<<endl;
		for(int i=0;i<countArray;i++){
			Student sd=arrSd[i];
			int id=sd.id;
			rePlace(sd.name,' ','_');
			string name=sd.name;
			float score=sd.score;
			fileOut<<id<<" "<<name<<" "<<score<<endl;
		}
		cout<< "\nSave to file " <<filename<< "  Success "<<endl;
		fileOut.close();
	}else{
		cout<<"Save to file Error"<<endl;
	}
};

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
							//Dung bien countArray o day de tro tiep den vi tri tiep theo trong mang da nhap lan truoc
	for(int i=countArray ; i<(n+countArray);i++){
		cout<<"fill information student "<<i+1<<endl;
		temp.id = inputId(i,arrSd);
		cout<<" Name student :"<<endl;
		fflush(stdin);
		getline(cin,temp.name);
		temp.score= inputScore();
		arrSd[i]=temp;
	}
	countArray+=n;			// cong them gia tri countArray khi ta tiep tap nhap thong tin, con tro se tro den vi tri tiep theo
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
			saveToFile(arrSd);
			break;
		case 4 :
			loadFromFile();
			break;
		case 0 :
			break;
		}
		
	}while(choose!=0);
	return 0;
}
