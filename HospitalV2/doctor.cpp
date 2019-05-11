#include "doctor.h"

//c'tor and d'tor
Doctor::Doctor(char* name, char* specialty, Department* depart) : StaffMember(name, depart)
{
	cout << "In Doctor c'tor..." << endl;
	setSpecialty(specialty);
}

//why we need default???
Doctor::Doctor() : StaffMember(name, nullptr)
{
	cout << "In Doctor default c'tor..." << endl;
	setSpecialty(0);
	this->department = 0;
}

Doctor::Doctor(const Doctor& other)
{
	cout << "In Doctor::Doctor(copy)\n";
	*this = other;
}

Doctor::~Doctor()
{
	cout << "In Docctor d'tor..." << endl;
	delete[] specialty;
}

//getters and setters
//int Doctor::getId() { return id; }
//char* Doctor::getName() const { return name; }

//void Doctor::setName(char* name)
//{
//	delete[] this->name;
//	this->name = new char[strlen(name) + 1];
//	strcpy(this->name, name);
//}

char* Doctor::getSpecialty() const { return specialty; }

void Doctor::setSpecialty(char* specialty)
{
	delete[] this->specialty;
	this->specialty = new char[strlen(specialty) + 1];
	strcpy(this->specialty, specialty);
}

void Doctor::setDepartment(Department* dep)
{
	department = dep;
}

Department* Doctor::getDepartment() const
{
	return this->department;
}

//operators
const Doctor& Doctor::operator=(const Doctor& other)
{
	cout << "In Doctor::operator=" << endl;
	StaffMember::operator=(other);

	delete[]specialty;
	specialty = new char[strlen(other.specialty) + 1];
	strcpy(specialty, other.specialty);

	return *this;
}


//methods
void Doctor::show() {

	StaffMember::show();
	cout << ", " << "Specialty: " << specialty;
}