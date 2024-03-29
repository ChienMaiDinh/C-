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
		this->m_virusList.push_front(*iter);
	}
}




void Patient::InitResistance(){
	m_resistance = bornRanDomNumber(1000,9000);
	std::cout <<"Total Blood Patient "<< m_resistance << "\n";
}

void Patient::DoStart(){
	this->m_virusList.clear();		
	this->m_state = 1;	
	int temp = bornRanDomNumber(10, 20);
	for (int i = 0; i < temp;  i++){
		Sleep(200);
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
	
	int countVirus = 0;
	int sumBloodVirus = 0;
	int dem =0 ;
	//duyet list tu head den tail , sau do iter tro it den null thi dung;
	for (std::list<MyVirus *> ::iterator iter = this->m_virusList.begin(); iter != this->m_virusList.end();) {
		dem++;
		std::cout << "\nCheck Size :  "<<dem<<" \n";
		std::cout <<"total Size Virus "<< m_virusList.size() << " \n";
		
		(*iter)->ReduceResistance(medicine_resistance);
			if ((*iter)->Get_m_resistance()> 0) {
				std::list<MyVirus *> listTemp = (*iter)->Doclone();			
				this->Set_ListVirus(listTemp);
			sumBloodVirus += (*iter)->Get_m_resistance();
			std::cout << "My blood recently Virus :  " << (*iter)->Get_m_resistance() << "\n";
			std::cout << "Total blood Virus : " << sumBloodVirus << "\n";
			countVirus++;
			if (this->m_resistance < sumBloodVirus) {
				std::cout << "Total blood patient just  " << this->m_resistance << " :E \n";
				std::cout << " \n\n\t      You Die, You were killed by " << countVirus << " viruses in total "<< m_virusList.size() <<" Virus ";
				for (auto auTo : this->m_virusList) {
					delete auTo;
				}
				this->m_virusList.clear();
				this->m_state = (0);
				break;
			}
			++iter;
		}else {
				MyVirus* p = (*iter);
				iter = m_virusList.erase(iter);			
				if (p != nullptr)
				{
					delete p;
					p = nullptr;
				}
				if (iter == m_virusList.end()) {
					std::cout << "\n\n\t    Congratulations , You Know Professional killer Virus  \t\t";
					this->Set_m_state(0);
				}
		}
	}
	if (this->Get_m_state ()== 1) {
		std::cout << "\n\t\t\t You Still Live ";
	}
	std::cout << "\n";
	std::cout << "\t\t You have used take medicine value : " << medicine_resistance << "\n";
	std::cout << "\t\t========================================\n\n";
	return this->Get_m_state();
}


int Patient::bornRanDomNumber(int head, int tail){
	srand(time(NULL));
	Sleep(200);
	int temp = rand() % (tail - head + 1) + head;
	return temp;
}

void Patient::DoDie(){
	this->m_state = 0;
	if (!m_virusList.empty())
	{
		for (auto auTo : this->m_virusList) {
			delete auTo;
		}
	}	
	this->m_virusList.clear();
}



Patient::Patient(){
	this->InitResistance();
	this->DoStart();
}


Patient::~Patient(){
	DoDie();
}
