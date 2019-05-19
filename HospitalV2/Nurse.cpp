#include "Nurse.h"

Nurse::Nurse(const char* name, int y_exp, Department* depart) : StaffMember(name, depart)
{
	cout << "In Nurse c'tor..." << endl;
	years_of_experience = y_exp;
}

Nurse::~Nurse()
{
	cout << "In Nurse d'tor..." << endl;
}

//getters and setters
//int Nurse::getId() { return id; }

//char* Nurse::getName() const { return name; }

int Nurse::getYearsOfExperience() const { return years_of_experience; }

//void Nurse::setName(char* name)
//{
//	delete[] this->name;
//	this->name = new char[strlen(name) + 1];
//	strcpy(this->name, name);
//}
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
	cout << "In Doctor::operator=" << endl;
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


