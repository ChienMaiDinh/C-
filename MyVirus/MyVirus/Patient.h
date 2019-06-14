#pragma once
#include "MyVirus.h"
#include <list>
class Patient
{
	int m_resistance;		//his natural resistance
	int m_state;//0 – DIE, 1 - ALIVE
	std::list<MyVirus*> m_virusList;	// The current virus in his bod
public:
	//Save tam thoi list Doclone sinh ra
	static std::list<MyVirus*> Temp_virusList;	
	int Get_m_resistance();
	void Set_m_resistance(int resistance);
	int Get_m_state();
	void Set_m_state(int state);
	std::list<MyVirus*> Get_ListVirus();
	void Set_ListVirus();
	void InitResistance();
	void DoStart();
	void TakeMedicine(int resistance);
	Patient();
	~Patient();
};

