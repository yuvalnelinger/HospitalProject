#ifndef __PATIENT_H
#define __PATIENT_H

#include <iostream>
using namespace std;

#include "department.h"

enum eGender { MALE, FEMALE };

class Patient
{
private:
	char* name;
	int id;
	int yearOfBirth;
	eGender gender;
	Department* currentDepartment;
public:

	//c'tor
	Patient(char* newName,int newId, int newYear,eGender newGen,Department* dep);

	//getters
	char* getPatientName() const;
	int getId() const;
	int getYearOfBirth() const;
	eGender getGender() const;
	Department* getPatientDepartment() const;

	//methods
	void show() const;
};

#endif
