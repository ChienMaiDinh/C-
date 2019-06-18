#include "Dengue.h"
#include <iostream>
#include <string>
#include "Patient.h"
#include "MyVirus.h"
#include <list>
#include <cstdlib>
#include <Windows.h>

Dengue::Dengue(){
	DoBorn();
	initresistance();
}


Dengue::~Dengue(){
	this->Dodie();
}

Dengue::Dengue(Dengue *p)
{
}

Dengue::Dengue(char * dna, int resistance, std::string protein) : MyVirus(m_dna, m_resistance) {
	this->m_protein = protein;
}


std::string Dengue::Get_m_protein(){
	return this->m_protein;
}

void Dengue::Set_m_protein(std::string protein){
	this->m_protein = protein;
}

void Dengue::DoBorn(){
	srand(time(NULL));
	LoadADNInformation();
	std::string temp[3] = { "NS5","E","NS3"};
	this->m_protein=temp[rand() % 3];
}

std::list<MyVirus *> Dengue::Doclone(){
	//tao 2 ban sao clone
	std::list<MyVirus *> list;
	Dengue *p1 = new Dengue();
	Dengue *p2 = new Dengue();
	p1->m_resistance = this->m_resistance;
	p1->m_protein = this->m_protein;
	p2->m_resistance = this->m_resistance;
	p2->m_protein = this->m_protein;
	std::string str = this->m_dna;
	for (int i = 0;i < str.size();i++)
	{
		p1->m_dna[i] = str[i];
		p2->m_dna[i] = str[i];
	}
	list.push_back(p1);
	list.push_back(p2);
	return list;
}
void Dengue::Dodie(){
	delete[]this->m_dna;
}

void Dengue::initresistance(){
	srand(time(NULL));
	if(this->m_protein.compare("NS3")==0) {
		m_resistance = rand() % 10 + 1;
		std::cout << " NS3 have " << m_resistance << " blood\n";
	}else if (this->m_protein.compare("E")==0) {
		m_resistance = rand() % 10 + 21;
		std::cout << " E have " << m_resistance << " blood\n";
	}else{
		m_resistance = rand() % 10 +11;
		std::cout << " NS5 have " << m_resistance << " blood\n";
	};
}