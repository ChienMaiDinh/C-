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

	void DoBorn() override;
	//virtual std::list<myvirus> doclone() = 0;
	//virtual bool dodie() = 0;
	//virtual void initresistance()=0;
};

