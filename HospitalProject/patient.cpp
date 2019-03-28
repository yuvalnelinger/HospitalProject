#include "patient.h"

Patient::Patient(char* newName, int newId, int newYear, eGender newGen, Department* dep)
{
	name = newName;
	id = newId;
	yearOfBirth = newYear;
	gender = newGen;
	currentDepartment = dep;
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
Department* Patient::getPatientDepartment() const
{
	return currentDepartment;
}

//methods
void Patient::show() const
{
	cout << "Patient Name: " << name << " Id: " << id << " Year Of Birth: " << " Gender: " << endl;
}


