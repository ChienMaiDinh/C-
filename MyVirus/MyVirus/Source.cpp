#include "MyVirus.h"
#include "Flu.h"
#include <iostream>

void main() {
	MyVirus *a = new Flu();
	a->Set_m_dna("asd");
	std::cout << a->Get_m_dna();
	a->Set_m_resistance(10);
	a->LoadADNInformation();
	std::cout << "uyuyu";
	std::cout << a->Get_m_dna();
	Flu * b=new Flu();
	a = b;

	a->DoBorn();


	

	system("pause");
}
