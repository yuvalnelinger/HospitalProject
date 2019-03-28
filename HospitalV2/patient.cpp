#include "patient.h"

Patient::Patient(char* newName, int newId, int newYear, eGender newGen)
{
	name = newName;
	id = newId;
	yearOfBirth = newYear;
	gender = newGen;
}


//getters
char* Patient::getPatientName() const
{
	return name;
}
int Patient::getId() const
{
	return id;
}
int Patient::getYearOfBirth() const
{
	return yearOfBirth;
}
eGender Patient::getGender() const
{
	return gender;
}


//methods
void Patient::show() const
{
	cout << "Patient Name: " << name << " Id: " << id << " Year Of Birth: " << " Gender: " << endl;
}


