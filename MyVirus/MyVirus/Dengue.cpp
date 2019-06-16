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
	Dodie();
}

Dengue::Dengue(char * dna, int resistance, std::string protein){
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
	//tao 1 ban sao goc vs 2 ban sao clone
	temp.push_back(new Dengue(m_dna, MyVirus::Get_m_resistance(), this->m_protein));
	temp.push_back(new Dengue(m_dna,MyVirus::Get_m_resistance(),this->m_protein));
	temp.push_back(new Dengue(m_dna, MyVirus::Get_m_resistance(), this->m_protein));
	std::list<MyVirus *> a;
	for (std::list<MyVirus *>::iterator iter = temp.begin();iter != temp.end();iter++) {
		//set mau lai sau khi ban goc bi tru
		(*iter)->Set_m_resistance(this->m_resistance);
		a.push_back(*iter);
	}
	a = temp;
	temp.clear();
	return a;
}

std::list<MyVirus*> Dengue::Dodie(){
	temp.clear();
	return temp;
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

 