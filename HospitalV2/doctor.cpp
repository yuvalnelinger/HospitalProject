#include "doctor.h"

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

Doctor::~Doctor()
{
	cout << "In Docctor d'tor..." << endl;
	delete[] specialty;
}

//getters and setters
int Doctor::getId() { return id; }
char* Doctor::getName() const { return name; }
char* Doctor::getSpecialty() const { return specialty; }

void Doctor::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
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


//methods
void Doctor::show() {

	StaffMember::show();
	cout << ", " << "Specialty: " << specialty
		<< endl;
}
/*

int Doctor::counter = 1000;

//c'tor and d'tor
Doctor::Doctor(char* name, char* specialty, Department* depart) : name(nullptr), specialty (nullptr)
{
	id = counter++;
	setName(name);
	setSpecialty(specialty);
	this->department = depart;
}

Doctor::~Doctor()
{
	delete[] name;
	delete[] specialty;
}

//getters and setters
int Doctor::getId() { return id; }

char* Doctor::getName() const { return name; }

char* Doctor::getSpecialty() const { return specialty; }

void Doctor::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
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

//methods
void Doctor::show() {
	cout << "Doctor ID: " << id
		<< " Name: " << name
		<< "Specialty: " << specialty
		<< endl;
}
*/