#include "Patient.h"
#include <list>
#include "Flu.h"
#include <iostream>
#include "Dengue.h"
#include <cstdlib>
#include <Windows.h>

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
	m_resistance = bornRanDomNumber(1000,9000);
	std::cout <<"Total Blood Patient "<< m_resistance << "\n";
}

void Patient::DoStart(){
	this->m_virusList.clear();		//xóa list
	this->m_state = 1;	
	//int temp=rand() % 11 + 10;
	int temp = bornRanDomNumber(10, 20);
	for (int i = 0; i < temp;  i++){
		//if (rand() % 2 == 0)
		Sleep(500);
		if (bornRanDomNumber(0,1) == 1) {
			std::cout <<i+1<< "	.Born Virus Dengue ";
			this->m_virusList.push_back(new Dengue());
		}else {
			std::cout <<i+1<< "	.Born Virus Flu ";
			this->m_virusList.push_back(new Flu());
		}
	} 
}

int Patient::TakeMedicine(int medicine_resistance){
	std::list<MyVirus *> ::iterator temp;
	std::list<MyVirus *> listTemp;
	int countVirus = 0;
	int sumBloodVirus = 0;
	int dem =0 ;
	//duyet list tu head den tail , sau do iter tro it den null thi dung;
	for (std::list<MyVirus *> ::iterator iter = this->m_virusList.begin(); iter != this->m_virusList.end();) {
		dem++;
		std::cout << "\nCheck Size :  "<<dem<<" \n";
		std::cout <<"total Size Virus "<< m_virusList.size() << " \n";
		
		listTemp = (*iter)->ReduceResistance(medicine_resistance);
		if ((*iter)->Get_m_resistance()> 0) {
			this->Set_ListVirus(listTemp);
			sumBloodVirus += (*iter)->Get_m_resistance();
			std::cout << "My blood recently Virus :  " << (*iter)->Get_m_resistance() << "\n";
			std::cout << "Total blood Virus : " << sumBloodVirus << "\n";
			countVirus++;
			temp = iter;
			iter++;
			m_virusList.erase(temp);
			if (this->m_resistance < sumBloodVirus) {
				std::cout << "Total blood patient just  " << this->m_resistance << " :E \n";
				std::cout << " \n\n        You Die, You were killed by " << countVirus << " viruses in total "<< m_virusList.size() <<" Virus ";
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
	this->Set_m_state(0);
	return this->Get_m_state();
}


int Patient::bornRanDomNumber(int head, int tail){
	srand(time(NULL));
	Sleep(500);
	int temp = rand() % (tail - head + 1) + head;
	return temp;
}

bool Patient::DoDie(){	
	return true;
}



Patient::Patient(){
	this->InitResistance();
	this->DoStart();
}


Patient::~Patient(){
	DoDie();
}
