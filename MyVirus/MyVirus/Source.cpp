#include "MyVirus.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Patient.h"
#include <iostream>

int main()

{ 
	srand(time(NULL));
	Patient p;
	int t = 0;
	int a = 1;
	while (p.Get_m_state() == 1)
	{
		std::cout << " \n\nKill Virus slowly, Hope you waiting for program process , thank you \n";
		printf(" \nTake Medicine (0 = NO, 1 = YES) \n");
		std::cin>>t;
		if (t == 1)
		{
			std::cout << "\n\n\t\tTake Medicine Time : " << a << "\n\n";
			std::cout << "============================================\n\n";
			a++;
			int min = 1;
			int max = 5;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			std::cout << "Value medicine :" << medicine_resistance << "\n\n";

			p.TakeMedicine(medicine_resistance);
		}
	}
	system("pause");
}
