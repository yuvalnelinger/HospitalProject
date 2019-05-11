#include "Surgeon.h"
#include "StaffMember.h"
#include "doctor.h"

Surgeon::Surgeon(const Doctor& base, int num_of_surgeries) : Doctor(base)
{
	cout << "test8" << endl;
	cout << "In Surgeon c'tor..." << endl;
	this->num_of_surgeries = num_of_surgeries;
	cout << "test9" << endl;
}

Surgeon::Surgeon(const Surgeon& other) : Doctor(other)
{
	cout << "In Surgeon copy..." << endl;
	*this = other;
}

void Surgeon::addSurgery()
{
	this->num_of_surgeries++;
}

int Surgeon::getNumOfSurgeries() const
{
	return this->num_of_surgeries;
}

void Surgeon::show() const
{
	StaffMember::show();
	Doctor::show();
	cout << ", number of surgeries: " << num_of_surgeries
		<< endl;
}


