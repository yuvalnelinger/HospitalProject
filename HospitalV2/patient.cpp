#include "patient.h"

Patient::Patient(char* newName, int newId, int newYear, int newGen)
{
	cout << "In Patient c'tor..." << endl;
	id = newId;
	name = newName;
	yearOfBirth = newYear;
	gender = newGen;
	curr_deparement = nullptr;

	arr_of_visitations = new Visit*[5];
	num_of_visitations = 0;
}

Patient::~Patient()
{
	cout << "In Patient d'tor..." << endl;
	delete[]name;

	for (int i = 0; i < num_of_visitations; i++)
		delete arr_of_visitations[i];
}

//getters and setters
int Patient::getId() const { return id; }

char* Patient::getName() const { return name; }

int Patient::getYearOfBirth() const { return yearOfBirth; }

int Patient::getGender() const { return gender; }

void Patient::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Patient::setYearOfBirth(int year)
{
	this->yearOfBirth = year;
}

void Patient::setGender(int gender)
{
	this->gender = gender;
}

void Patient::setCurrDepartment(Department* dep)
{
	this->curr_deparement = dep;
}


//methods
void Patient::show() const
{
	cout << "Patient Name: " << name << " Id: " << id << " Year Of Birth: " << " Gender: " << gender << endl;
}

void Patient::addVisit(Visit* newVisit)
{
	arr_of_visitations[num_of_visitations++] = newVisit;
}

