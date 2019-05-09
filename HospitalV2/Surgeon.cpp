#include "Surgeon.h"

Surgeon::Surgeon(char* name, char* specialty, Department* depart) : StaffMember(name),Doctor(name,specialty,depart) //check if this is right
{
	cout << "In Surgeon c'tor..." << endl;
	this->num_of_surgeries=0;
}

void Surgeon::addSurgery()
{
	this->num_of_surgeries++;
}

int Surgeon::getNumOfSurgeries() const
{
	return this->num_of_surgeries;
}


