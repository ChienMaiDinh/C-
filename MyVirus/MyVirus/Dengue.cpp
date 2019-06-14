#include "Dengue.h"
#include <string>
#include "Patient.h"
#include "MyVirus.h"
#include <list>


Dengue::Dengue()
{
}


Dengue::~Dengue()
{
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

void Dengue::Doclone(){
	temp.push_back(new Dengue(m_dna, m_resistance, m_protein));
	temp.push_back(new Dengue(m_dna, m_resistance, m_protein));
	Patient::Temp_virusList.merge(temp);
}

