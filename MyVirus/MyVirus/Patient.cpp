#include "Patient.h"
#include <list>
#include "Flu.h"
#include <iostream>
#include "Dengue.h"


int Patient::Get_m_resistance(){
	return this->m_resistance;
}

void Patient::Set_m_resistance(int resistance){
	this->m_resistance = resistance;
}

int Patient::Get_m_state(){
	return this->m_state;
}

void Patient::Set_m_state(int state){
	this->m_state = state;
}

std::list<MyVirus*> Patient::Get_ListVirus(){
	return this->m_virusList;
}

void Patient::Set_ListVirus(){
	this->m_virusList.merge(Temp_virusList);
}



void Patient::InitResistance(){
	srand(time_t(NULL));
	//random 8001 gia tri tu 1000>9000
	this->m_resistance = rand()% (8001) +1000;
}

void Patient::DoStart(){
	srand(time_t(NULL));
	this->m_virusList.clear();		//xóa list
	this->m_state = 1;	
	//rd 11 gia tri tu 10>20
	int temp=rand() % 11 + 10;
	for (int i = 0; i < temp;  i++){
		if ((rand() % 2) == 1) {
			this->m_virusList.push_back(new Flu());
		}
		else {
			this->m_virusList.push_back(new Dengue());
		}
	}
}

void Patient::TakeMedicine(int resistance){

}

Patient::Patient(){
	this->InitResistance();
	this->DoStart();
}


Patient::~Patient(){
}
