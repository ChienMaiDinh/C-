#include "MyPoint.h"
#include <math.h>
#include <iostream>
using namespace std;


MyPoint::MyPoint(){
}


MyPoint::MyPoint(int mmPosX, int mmPosY) {
	this->mPosX = mmPosX;
	this->mPosY = mmPosY;
}

MyPoint::~MyPoint() {
}

void MyPoint::SetX(int mmPosX) {
	this->mPosX = mmPosX;
}

int MyPoint::GetX() {
	return this->mPosX;
}

void MyPoint::SetY(int mmPosY) {
	this->mPosY = mmPosY;
}

int MyPoint::GetY() {
	return this->mPosY;
}

void MyPoint::Display() {
	cout << "value of mPosX " << this->mPosX << endl;
	cout << "value of mPosY " << this->mPosY << endl;
}

double MyPoint::Distance(MyPoint temp) {
	int a = (this->mPosX - temp.mPosX)*(this->mPosX - temp.mPosX);
	int b = (this->mPosY - temp.mPosY)*(this->mPosY - temp.mPosY);
	return sqrt(a+b);
}


void main() {
	MyPoint *pointOne = new MyPoint(1, 1);
	MyPoint *pointTwo = new MyPoint();
	pointTwo->SetX(3);
	pointTwo->SetY(5);
	
	cout << "distance between  pointOne  and point Two :" << endl << pointOne->Distance(*pointTwo)<<endl;

		system("pause");
}