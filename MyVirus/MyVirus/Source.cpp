#include "MyVirus.h"
#include <iostream>

void main() {
	MyVirus *a = new MyVirus();
	a->Set_m_dna("asd");
	std::cout << a->Get_m_dna();
	a->Set_m_resistance(10);
	a->LoadADNInformation();
	std::cout << "uyuyu";
	std::cout << a->Get_m_dna();
	system("pause");
}