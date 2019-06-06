#include <iostream> 
using namespace std;

void inPutUser();
void outPutArray(char **arrChoose,int n);
void playerChoose(char **arrChoose,int n,char user);
void playGame(char **arrChoose,int n);
void creatArray(char **arrChoose,int n);
bool checkChoose(char **arrChoose,int i,int j);
bool checkWin(char **arrChoose,int n,char user);
bool checkRows(char **arrChoose,int n,char user);
bool checkDuongCheoTrai(char **arrChoose,int n,char user);
bool checkDuongCheoPhai(char **arrChoose,int n,char user);
bool checkColumns(char **arrChoose,int n,char user);

char user1[10];
char user2[10];
int rows;
int columns;

void inPutUser(){
	cout <<"Start Game " <<endl;
	cout <<"Enter Player 1 Name :";
	cin >> user1;
	cout <<"Enter Player 2 Name :";
	cin >> user2;
}

void playGame(char **arrChoose,int n){
	// bien k,q de dem so lan danh cua nguoi choi
	int k=1,q=1;
	// for de duyet het so phan tu
	for(int i=1;i<=n*n;i++){
	//danh dau nguoi choi , 1X 2O
		char user;
		if((i%2)!=0){
			user= 'X';
			cout <<user1<<" Turn : "<<k<<endl;
			k++;
			//nguoi choi chon
			playerChoose(arrChoose,n,user);
		}else{
			user= 'O';
			cout <<user2<<" Turn : "<<q<<endl;
			q++;
			playerChoose(arrChoose,n,user);
		}
		if(checkWin(arrChoose,n,user)){
			if(user=='X'){
				cout<<"congrations"<<endl;
				cout<< user1 <<" WIN "<<endl;
			}else{
				cout<<"congrations"<<endl;
				cout<< user2 <<" WIN "<<endl;
			}
			//neu win set lai i de thoat vong for
			i=n*n+1;
		}else{
			if(i==n*n){
				cout<< user1 <<" equal "<<user2<<endl;
			}
		}
	}
}

bool checkWin(char **arrChoose,int n,char user){
	if(checkRows(arrChoose,n,user)||checkDuongCheoTrai(arrChoose,n,user)||checkDuongCheoPhai(arrChoose,n,user)||checkColumns(arrChoose,n,user)){
		return true;
	}else{
		return false;
	}
}

bool checkDuongCheoTrai(char **arrChoose,int n,char user){	
	bool check=false;
	if(columns==rows){
		//bien count de xac dinh tat ca n phan tu co giong nhau hay k
		int count=0;
			for(int i=0;i<n;i++){
			if(user==arrChoose[i][i]){
				count++;
			}
		}
		if(count==n){
			check= true;
		}
	}
	return check;
}

bool checkDuongCheoPhai(char **arrChoose,int n,char user){	
	bool check=false;
	if(columns==n-1-rows){
				//bien count de xac dinh tat ca n phan tu co giong nhau hay k
		int count=0;
			for(int i=0;i<n;i++){
			if(user==arrChoose[i][n-1-i]){
				count++;
			}
		}
		if(count==n){
			check= true;
		}
	}
	return check;
}



bool checkRows(char **arrChoose,int n,char user){
		//bien count de xac dinh tat ca n phan tu co giong nhau hay k
	int count=0;
	for(int i=0;i<n;i++){
		if(arrChoose[rows][i]==user){
			count++;
		}
	}
	if(count!=n){
		return false;
	}else{
		return true;
	}
}
bool checkColumns(char **arrChoose,int n,char user){
	int count=0;
	for(int i=0;i<n;i++){
		if(arrChoose[i][columns]==user){
			count++;
		}
	}
	if(count!=n){
		return false;
	}else{
		return true;
	}
}

void playerChoose(char **arrChoose,int n,char user){ 
	//bien nguoi choi chon
	int addressChoose;
	//bien i,j se dai dien luu cot va hang cua nguoi chon
	int i=n,j=n;
	while(i>(n-1) || j>(n-1)){
		cin >> addressChoose;
		// vd: NxN=4x4 -> imax=jmax=3/ truoc tien bat nhap lai phan tu >33 va <0
		if(addressChoose>(10*(n-1)+n-1) || addressChoose <0){
			cout << " please input valid rows and colums"<<endl;
			i=n;
		}else{
		i=addressChoose/10;
		j=addressChoose%10;
			if(i<n && j<n){
				//check trung phan tu da chon tu truoc
				if(!checkChoose(arrChoose,i,j)){
					cout<< "please choose diffrence"<<endl;	
					i=n;			
				}
				//nhung phan tu con lai ko thoa man nhu (26, 15...)
			}else{
				cout<<"please input valid rows and colums"<<endl;
			}
		}
	}
	//luu thong tin lan chon gan nhat de checkWin de hon
	arrChoose[i][j]=user;
	rows=i;
	columns=j;
	outPutArray(arrChoose,n);
}
void creatArray(char **arrChoose,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n ;j++){
			arrChoose[i][j]='_';
		}
	}	
}

void outPutArray(char **arrChoose,int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n ;j++){
			cout<< "["<<arrChoose[i][j]<<"]";
		}
		cout<<endl;
	}	
}

bool checkChoose(char **arrChoose,int i,int j){
	//kiem tra phan tu vua chon da danh XO hay chua
	if(arrChoose[i][j]=='X' || arrChoose[i][j]=='O'){
		return false;
	}else{
		return true;
	}
}

int main(){
	cout <<"Welcome To Tic-tac-toe game! Play with your way!" << endl;
	cout <<"If you find any problem, please contact john.nguyen@gameloft.com" << endl;
	cout <<"SELECT YOUR MODE (1 - PLAY GAME, OTHERS - EXIT GAME):" << endl;
	int choose;
	cin >> choose;
	if(choose ==1){
		cout<<"Choose size dashboard "<<endl;
		int n;
		cin>> n;
		inPutUser();
		//so dong so cot cho mang 2 chieu cap phat dong
		//khai bao so dong
		char **arrChoose =new char *[n];
		for(int i=0;i<n;i++){
		//khai bao so cot
			arrChoose[i]=new char[n];
		}
		//Khoi tao mang 2 Chieu
		creatArray(arrChoose,n);
		outPutArray(arrChoose,n);
		
		//Vao phan game
		playGame(arrChoose,n);
	}
	return 0;
}
