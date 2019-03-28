#include <iostream>
using namespace std;

#include "doctor.h"

Doctor::Doctor(int newId, char* newName, char* newSpecialty)
{
	employeeId = newId;
	name = newName;
	specialty = newSpecialty;
}

Doctor::~Doctor() 
{
	delete[] name;
	delete[] specialty;
}

int Doctor::getEmpId() { return employeeId; }
char* Doctor::getName() const { return name; }
char* Doctor::getSpecialty() const { return specialty; }

//setters
void Doctor::setEmpId(int newId) {
	employeeId = newId;
}
void Doctor::setNamee(char* newName) {
	name = newName;
}
void Doctor::setSpecialty(char* newSpecialty) {
	specialty = newSpecialty;
}

//methods
void Doctor::show() {
	cout << "Doctor ID: " << employeeId << " Name: " << name << "Specialty: " << specialty << endl;
}
