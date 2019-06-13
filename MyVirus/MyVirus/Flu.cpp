#include "Flu.h"
#include "MyVirus.h"
#include <fstream>
#include <iostream>
#include <string>



void Flu::DoBorn(){
	LoadADNInformation();
}

void Flu::Set_m_color(int color){
	this->m_color = color;
}

int Flu::Get_m_color()
{
	return this->m_color;
}

Flu::Flu()
{
}


Flu::~Flu()
{
}
