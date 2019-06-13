#pragma once
#include "MyVirus.h"
class Flu : public MyVirus
{
private:
	int m_color;	 //color of Flu virus is blue (value 0x0000ff) or red (value 0xff0000)
public:
	void DoBorn();
	void DoClone();
	std::list<MyVirus> DoDie();
	void InitResistance();

	Flu();
	~Flu();
};

