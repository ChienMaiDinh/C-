#include "Dengue.h"
#include <iostream>
#include <string>
#include "Patient.h"
#include "MyVirus.h"
#include <list>
#include <time.h>


Dengue::Dengue()
{
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
	LoadADNInformation();
	std::string temp[3] = { "NS3","NS5","E" };
	this->m_protein = temp[rand() % 3];
}

std::list<MyVirus *> Dengue::Doclone(){
	temp.push_back(new Dengue(m_dna,MyVirus::Get_m_resistance(),this->m_protein));
	temp.push_back(new Dengue(m_dna, MyVirus::Get_m_resistance(), this->m_protein));
	std::list<MyVirus *> a = temp;
	temp.clear();
	return a;
}

std::list<MyVirus*> Dengue::Dodie(){
	temp.clear();
	return temp;
}

void Dengue::initresistance(){
	srand(time(NULL));
	if(this->m_protein.compare("NS3")) {
		m_resistance = rand() % 10 + 1;
		std::cout << "sinh ra virus co " << m_resistance << "mau Dengu\n";

	}else if (this->m_protein.compare("NS5")) {
		m_resistance = rand() % 10 + 11;
		std::cout << "sinh ra virus co " << m_resistance << "mau DEngu\n";

	}else {
		m_resistance = rand() % 10 + 21;
		std::cout << "sinh ra virus co " << m_resistance << "mau DEngu\n";
	}
}

