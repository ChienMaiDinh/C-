#include "Patient.h"



int Patient::Get_m_resistance()
{
	return this->m_resistance;
}

void Patient::Set_m_resistance(int resistance){
	this->m_resistance = resistance;
}

int Patient::Get_m_state()
{
	return this->m_state;
}

void Patient::Set_m_state(int state){
	this->m_state = state;
}

std::list<MyVirus*> Patient::Get_ListVirus(){
	return this->m_virusList;
}

void Patient::Set_ListVirus(std::list<MyVirus*> virusList){
	this->m_virusList = virusList;
}



void Patient::InitResistance(){
	srand(time_t(NULL));
	int ranDom = 0;
	for (int i = 4; i>0;i--) {
		if (i == 1) {
			ranDom += rand() % 10;
		}
		else {
			ranDom += (rand() % 10)*(i - 1);
		}
	}
	this->m_resistance = ranDom;
}

void Patient::DoStart(){
	int temp=rand() % 10 + 10;
	for (int i = 0; i < temp; int i++){
		MyVirus * a = new 
	}
}

Patient::Patient(){
	this->InitResistance();
}


Patient::~Patient()
{
}
