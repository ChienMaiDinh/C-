#pragma once
#include "MyVirus.h"
#include <string>
class Dengue:public MyVirus{ 
private:
	std::string m_protein;	//protein in virus represent the type of Dengue virus.
public:
	Dengue();
	~Dengue();
	Dengue(char * dna, int resistance, std::string protein);
	std::list<MyVirus *> temp;
	std::string Get_m_protein();
	void Set_m_protein(std::string protein);
	void DoBorn() override;
	std::list<MyVirus*> Doclone() override;
	//void Doclone() override;

	std::list<MyVirus*> Dodie() override;
	void initresistance() override;
};

