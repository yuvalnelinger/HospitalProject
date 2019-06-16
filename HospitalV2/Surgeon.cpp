#include "Surgeon.h"
#include "StaffMember.h"
#include "doctor.h"

//c'tor
Surgeon::Surgeon(const Doctor& base, int num_of_surgeries) : StaffMember(base.getName(), base.getDepartment()), Doctor(base), num_of_surgeries(num_of_surgeries)
{}

Surgeon::Surgeon(const Surgeon& other) : Doctor(other)
{
	this->num_of_surgeries = other.num_of_surgeries;
}

//getters
int Surgeon::getNumOfSurgeries() const
{
	return this->num_of_surgeries;
}

//operators
void Surgeon::toOs(ostream& os) const
{
	os << ", Specialty: " << specialty.c_str()
		<<", Number of surgeries: " << num_of_surgeries
		<< endl;
}

//methods
void Surgeon::addSurgery()
{
	this->num_of_surgeries++;
}

void Surgeon::show() const
{
	StaffMember::show();
	Doctor::show();
	cout << ", number of surgeries: " << num_of_surgeries
		<< endl;
}


