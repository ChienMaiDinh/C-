#pragma once
class MyVirus
{
private :
	char* m_dna;						 //to store the order of acid nucleic sequence (A, T, G,X)
	int m_resistance;					//the virus resistance ability (10 – 30)
public:
	MyVirus();
	~MyVirus();
	MyVirus(MyVirus * myVirus);
	void LoadADNInformation();				//Load DNA information from a ATGX.bin and store it in m_dna.
	int ReduceResistance(int medicine_resistance);

	int Get_m_resistance();
	void Set_m_resistance(int resistance);
	char* Get_m_dna();
	void Set_m_dna(char * dna);

	virtual void DoBorn() = 0;
	virtual void DoClone() = 0;
	virtual void DoDie() = 0;
	virtual void InitResistance()=0;

};

	