#include "MyVirus.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

MyVirus::MyVirus(){
}

MyVirus::~MyVirus(){
}

MyVirus::MyVirus(char * dna, int resistance){
	this->m_dna = dna;
	this->m_resistance = resistance;
}

MyVirus::MyVirus(const MyVirus & myVirus){
	this->m_resistance = myVirus.m_resistance;
	m_dna = new char;
	*m_dna = *myVirus.m_dna;
}


 

void MyVirus::LoadADNInformation(){
	ifstream inFile;
	string temp;
	inFile.open("ATGX.bin");
	if (inFile.is_open()) {
		getline(inFile, temp);
		char * cpyDNA = new char[temp.size() + 1];
		for (int i = 0; i < temp.size(); i++){
			cpyDNA[i] = temp[i];
		}
		cpyDNA[temp.size()] = '\0';
		this->Set_m_dna(cpyDNA);
		//cout << this->Get_m_dna();   //test 
		inFile.close();
	}else {
		cout << "Load file Error\n" ;
	}
	
}


void MyVirus::ReduceResistance(int medicine_resistance){
	this->m_resistance-= medicine_resistance;
}


int MyVirus::Get_m_resistance() {
	return this->m_resistance;
}

void MyVirus::Set_m_resistance(int resistance) {
	this->m_resistance = resistance;
}

char * MyVirus::Get_m_dna() {
	return this->m_dna;
}

void MyVirus::Set_m_dna(char * dna) {
	this->m_dna = dna;
}

