#include "Surgeon.h"
#include "StaffMember.h"
#include "doctor.h"

Surgeon::Surgeon(const Doctor& base, int num_of_surgeries) : StaffMember(base.getName(), base.getDepartment()), Doctor(base), num_of_surgeries(num_of_surgeries)
{
	cout << "test8" << endl;
	cout << "In Surgeon c'tor..." << endl;
	cout << "test9" << endl;
}

Surgeon::Surgeon(const Surgeon& other) : Doctor(other)
{
	cout << "In Surgeon copy..." << endl;
	this->num_of_surgeries = other.num_of_surgeries;
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


