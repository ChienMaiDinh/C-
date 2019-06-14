#include "Flu.h"
#include "MyVirus.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Patient.h"



Flu::Flu(char * dna, int resistance, int color) : MyVirus(m_dna, m_resistance){
	this->m_color = color;
}

void Flu::DoBorn(){
	LoadADNInformation();
	if(rand() % 2 == 1) {
		this->m_color = 0x0000ff;
	}else {
		this->m_color = 0xff0000;
	}
}

bool Flu::Dodie(){
	return true;
}

void Flu::Doclone(){
	std::list<MyVirus *> temp;
	temp.push_back(new Flu(m_dna, m_resistance, this->m_color));
	Patient::Temp_virusList.merge(temp);
}

void Flu::Set_m_color(int color){
	this->m_color = color;
}

int Flu::Get_m_color()
{
	return this->m_color;
}

Flu::Flu(){
	DoBorn();
}


Flu::~Flu(){
}
