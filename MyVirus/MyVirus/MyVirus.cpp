#include "MyVirus.h"

MyVirus::MyVirus(){

}

MyVirus::~MyVirus(){
}

MyVirus::MyVirus(MyVirus * myVirus){
}

void MyVirus::LoadADNInformation(){
}

int MyVirus::ReduceResistance(int medicine_resistance){
	return this->m_resistance - medicine_resistance;
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


