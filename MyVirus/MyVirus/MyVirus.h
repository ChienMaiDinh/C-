#pragma once
#include <list>
class MyVirus
{
protected :								
	char* m_dna;						 //to store the order of acid nucleic sequence (A, T, G,X)
	int m_resistance;					//the virus resistance ability (10 – 30)
public:


	MyVirus();
	~MyVirus();
	MyVirus(char * dna, int resistance);
	MyVirus(const MyVirus & myVirus);
	void LoadADNInformation();				//Load DNA information from a ATGX.bin and store it in m_dna.
	std::list<MyVirus*> ReduceResistance(int medicine_resistance);

	int Get_m_resistance();
	void Set_m_resistance(int resistance);
	char* Get_m_dna();
	void Set_m_dna(char * dna);

	virtual void DoBorn() = 0;
	virtual std::list<MyVirus*> Doclone() = 0;
	virtual std::list<MyVirus*> Dodie() = 0;
	virtual void initresistance()=0;
	

};

	