#pragma once
#include <list>

class MyVirus
{
protected :								
	char* m_dna;						 //to store the order of acid nucleic sequence (A, T, G,X)
	int m_resistance;					//the virus resistance ability (10 – 30)
	MyVirus * next;
public:
	MyVirus();
	~MyVirus();
	MyVirus(const MyVirus & myVirus);
	MyVirus(char * const dna, int resistance, MyVirus * const next = 0);
	void LoadADNInformation();				//Load DNA information from a ATGX.bin and store it in m_dna.
	int ReduceResistance(int medicine_resistance);

	int Get_m_resistance();
	void Set_m_resistance(int resistanc	e);
	char* Get_m_dna();
	void Set_m_dna(char * dna);

	virtual void DoBorn() = 0;
	//virtual std::list<myvirus> doclone() = 0;
	//virtual bool dodie() = 0;
	//virtual void initresistance()=0;

};

	