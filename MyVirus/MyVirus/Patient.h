#pragma once
#include "MyVirus.h"
#include <list>
class Patient
{
	int m_resistance;		//his natural resistance
	std::list<MyVirus*> m_virusList;	// The current virus in his body
	int m_state;			//0 – DIE, 1 - ALIVE
public:

	int Get_m_resistance();
	void Set_m_resistance(int resistance);
	int Get_m_state();
	void Set_m_state(int state);
	std::list<MyVirus*> Get_ListVirus();
	void Set_ListVirus(std::list<MyVirus *> virusList);

	void InitResistance();
	void DoStart();
	Patient();
	~Patient();
};

