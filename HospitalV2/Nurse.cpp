#include "Nurse.h"

//c'tor and d'tor
Nurse::Nurse(const char* name, int y_exp, Department* depart) : StaffMember(name, depart)
{
	years_of_experience = y_exp;
}

Nurse::~Nurse() {}

//getters and setters
int Nurse::getYearsOfExperience() const { return years_of_experience; }

void Nurse::setYearsOfExperience(int years)
{
	this->years_of_experience = years;
}

void Nurse::setDepartment(Department* depart)
{
	this->department = depart;
}

//operators
const Nurse& Nurse::operator=(const Nurse& other)
{
	StaffMember::operator=(other);

	years_of_experience = other.years_of_experience;

	return *this;
}

void Nurse::toOs(ostream& os) const
{
	os << ", Years of experience: " << years_of_experience
		<< endl;
}


//methods
void Nurse::show() const
{
	StaffMember::show();
	cout << ", " << "Years of experience: " << years_of_experience
		<< endl;
}


