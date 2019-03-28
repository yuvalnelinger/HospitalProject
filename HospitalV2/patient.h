#ifndef __PATIENT_H
#define __PATIENT_H

#include <iostream>
using namespace std;

enum eGender { MALE, FEMALE };

class Patient
{
private:
	char* name;
	int id;
	int yearOfBirth;
	eGender gender;
public:

	//c'tor
	Patient(char* newName, int newId, int newYear, eGender newGen);

	//getters
	char* getPatientName() const;
	int getId() const;
	int getYearOfBirth() const;
	eGender getGender() const;

	//methods
	void show() const;
};

#endif
