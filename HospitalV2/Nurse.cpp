#include "Nurse.h"

Nurse::Nurse(char* name, int y_exp, Department* depart) : StaffMember(name)
{
	cout << "In Nurse c'tor..." << endl;
	years_of_experience = y_exp;
	department = depart;
}

Nurse::~Nurse()
{
	cout << "In Nurse d'tor..." << endl;
}

//getters and setters
int Nurse::getId() { return id; }

char* Nurse::getName() const { return name; }

int Nurse::getYearsOfExperience() const { return years_of_experience; }

void Nurse::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void Nurse::setYearsOfExperience(int years)
{
	this->years_of_experience = years;
}

void Nurse::setDepartment(Department* depart)
{
	this->department = depart;
}

void Nurse::show() const
{
	cout << "Nurse ID: " << "tofillin"
		<< " Name: " << name
		<< "Years of experience: " << years_of_experience
		//<< "Department: " << department->getDepName()
		<< endl;
}


