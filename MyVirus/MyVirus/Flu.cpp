#include "Flu.h"
#include "MyVirus.h"
#include <fstream>
#include <iostream>
#include <string>



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
