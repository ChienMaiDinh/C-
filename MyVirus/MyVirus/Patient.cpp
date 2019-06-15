#include "Patient.h"
#include <list>
#include "Flu.h"
#include <iostream>
#include "Dengue.h"
#include <time.h>

int Patient::Get_m_resistance(){
	return this->m_resistance;
}

void Patient::Set_m_resistance(int resistance){
	this->m_resistance = resistance;
}

int Patient::Get_m_state(){
	return this->m_state;
}

void Patient::Set_m_state(int state){
	this->m_state = state;
}

std::list<MyVirus*> Patient::Get_ListVirus() {
	return this->m_virusList;
}

void Patient::Set_ListVirus(std::list<MyVirus*> temp){
	for (std::list<MyVirus *>::iterator iter = temp.begin();iter != temp.end();iter++) {
		this->m_virusList.push_back(*iter);
	}
	temp.clear();
}









void Patient::InitResistance(){
	srand(time_t(NULL));
	//random 8001 gia tri tu 1000>9000
	this->m_resistance = rand()% (8001) +1000;
}

void Patient::DoStart(){
	srand(time(NULL));
	this->m_virusList.clear();		//xóa list
	this->m_state = 1;	
	//rd 11 gia tri tu 10>20
	int temp=rand() % 11 + 10;
	for (int i = 0; i < temp;  i++){
		if ((rand() % 2) == 1) {
			this->m_virusList.push_back(new Flu());
			std::cout << "-----------";
		}
		else {
			this->m_virusList.push_back(new Dengue());
			std::cout << "++++++";
		}
	}
}

void Patient::TakeMedicine(int medicine_resistance){
	std::list<MyVirus *> ::iterator temp;
	std::list<MyVirus *> listTemp;
	int countVirus = 0;
	int sumBloodVirus = 0;
	int dem =0 ;
	//duyet list tu head den tail , sau do iter tro it den null thi dung;
	for (std::list<MyVirus *> ::iterator iter = this->m_virusList.begin(); iter != this->m_virusList.end();) {
		dem++;
		std::cout << "LAN  "<<dem<<"  :\n\n";
		std::cout <<"size virus "<< m_virusList.size() << " \n";
		
		listTemp = (*iter)->ReduceResistance(medicine_resistance);
		//	std::cout <<"so virus con : "<< m_virusList.size()-dem << " \n\n";
		if ((*iter)->Get_m_resistance()> 0) {
			this->Set_ListVirus(listTemp);
			sumBloodVirus += (*iter)->Get_m_resistance();
			std::cout << "luong mau virus hien tai con " << (*iter)->Get_m_resistance() << "\n";
			std::cout << "tong mau virus : " << sumBloodVirus << "\n";
			//this->m_resistance-= (*iter)->Get_m_resistance();
			countVirus++;
			if (this->m_resistance < sumBloodVirus) {
				std::cout << "tong mau cua ban chi " << this->m_resistance << " :E \n";
				std::cout << " \n\n        You Die, You were killed by " << countVirus << " viruses   \t\t";
				break;
			}
		}else {
				temp = iter;
				iter++;
				m_virusList.erase(temp);
				if (iter == m_virusList.end()) {
					std::cout << "\n\n    Congratulations , You Know Professinal kill Virus  \t\t";
				}
		}
	}
	/*std::cout << m_virusList.size() << " size virus tong hien tai la : \n";
	if (this->m_resistance < sumBloodVirus) {
		std::cout << " You Die, You were killed by "<< countVirus <<" viruses";
	}else {
		
	}*/
}


bool Patient::DoDie()
{	
	return true;
}



Patient::Patient(){
	this->InitResistance();
	this->DoStart();
}


Patient::~Patient(){
	DoDie();
}
