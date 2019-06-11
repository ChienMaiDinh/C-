#include <iostream>
#include <string>
#include <iostream>
#include <fstream>



using namespace std;


struct Student {
	int id;
	string name;
	float score;
};

int countArray=0; 							//bien cam canh giu chi so vi tri con tro Student dang tro toi
void outPutInfor(Student *arrSd);			 //ham xuat thong tin trong phien lam viec hien tai
void inPutInfor(int n,Student * arrSd); 	//ham nhap thong tin Student
void rePlace(string &str,char before,char after); //xu ly doi ki tu dua vao file 
int inputId(int i,Student* arrSd);   		// ham check ID trung
float inputScore(); 						//ham check diem < 0 va >10
void menu();								//ham in thong tin lua chon
void saveToFile(Student* arrSd); 			// ham luu mang da nhap vao file
void loadFromFile();						//ham load thong tin tu file ra

void outPutInfor(Student *arrSd){
		cout<< "All Information recently : \n\n";
		cout<< " ID \t\tFULL NAME\t\tSCORE\n\n";
	for(int i=0;i<countArray;i++ ){
		cout<< arrSd[i].id<<"\t\t"<<arrSd[i].name<<"\t\t\t"<<arrSd[i].score<<endl;
	}
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
	cout << "\n\n";
	cout << "-------------------MENU-------------------\n";
	cout << "	1.	input \n";
	cout << "	2.	Display \n";
	cout << "	3.	Save to file \n";
	cout << "	4.	Load from file \n";
	cout << "	0.	Exit \n";
	cout << "-----------------------------------------\n";
	cout << "Choose : \n\n\n";

}


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

void rePlace(string &str,char before,char after){
	for(int i=0; i< str.length();i++){
		if(str.at(i)==before){
			str.at(i)=after;
		}
	}
};

void loadFromFile(){
	ifstream fileIn;
	fileIn.open("Student.txt",ios_base::in);
	if(fileIn.is_open()){
		int count;
		fileIn>>count;
		cout<<"Load FILE to student : \n\n";
		cout<< "number of student file:  "<<count<<"\n\n";
		for(int i=0;i<count;i++){
			Student sd;
			fileIn>>sd.id;
			fileIn>>sd.name;
			rePlace(sd.name,'_',' ');
			fileIn>>sd.score;
			cout<< sd.id<<"\t\t"<<sd.name<<"\t\t\t"<<sd.score<<endl;
		}
		fileIn.close();
	
	}else{
		cout<<"Load file Error"<< endl;
	}
}




int main() {

	Student * arrSd = new Student[100];
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
