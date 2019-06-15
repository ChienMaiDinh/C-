#pragma once
#include "MyVirus.h"
class Flu : public MyVirus
{
private:
	int m_color;	 //color of Flu virus is blue (value 0x0000ff) or red (value 0xff0000) 
public:
	std::list<MyVirus *> temp;
	Flu(char * dna, int resistance, int color);
	void DoBorn() override;
	std::list<MyVirus*> Dodie() override;
	std::list<MyVirus*> Doclone() override;
	void initresistance() override;
	//void Doclone() override;
	void Set_m_color(int color);
	int Get_m_color();
	

	Flu();
	~Flu();
};

