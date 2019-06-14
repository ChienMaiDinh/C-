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
	
	std::string Get_m_protein();
	void Set_m_protein(std::string protein);
	std::list<MyVirus *> temp;

	void DoBorn() override;
	void Doclone() override;
	bool Dodie() override;
	void initresistance() override;
};

