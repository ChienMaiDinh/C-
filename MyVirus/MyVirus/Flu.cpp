#include "Flu.h"
#include "MyVirus.h"
#include <iostream>
#include <string>
#include "Patient.h"
#include <cstdlib>



Flu::Flu(char * dna, int resistance, int color) : MyVirus(m_dna, m_resistance){
	this->m_color = color;
}

void Flu::DoBorn(){
	srand(time(NULL));
	LoadADNInformation();
	if (rand() % 2 == 1) {
		std::cout << " Blue";
		this->m_color = 0x0000ff;
	}else {
		std::cout << " Red ";
		this->m_color = 0xff0000;
	}
}

void Flu::Dodie(){
	delete[]this->m_dna;	
}

std::list<MyVirus *> Flu::Doclone(){
	std::list<MyVirus *> list;
	Flu *flu = new Flu();
	flu->m_resistance = this->m_resistance;
	flu->m_color = this->m_color;
	std::string str = this->m_dna;
	for (int i = 0;i < str.size();i++)
	{
		flu->m_dna[i] = str[i];
	}
	list.push_back(flu);
	return list;
}

void Flu::initresistance(){
	srand(time(NULL));
	if (this->m_color = 0x0000ff) {
		//rd 6 phan tu tu 10-15 
		m_resistance = rand() % 6 + 10; 
		std::cout << " have " << m_resistance << " blood\n";
	}else {
		//rd 11 phan tu tu 10-20
		m_resistance = rand() % 11 + 10;
		std::cout << " have " << m_resistance << " blood\n";
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
	initresistance();
}


Flu::~Flu(){
	this->Dodie();
}
