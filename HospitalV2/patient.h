#ifndef __PATIENT_H
#define __PATIENT_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "visit.h"

class Department;

class Patient
{
public:
	//enum eGender { MALE, FEMALE };

	//c'tor and d'tor
	Patient(char* newName, int newId, int newYear, int newGen);
	~Patient();

	//getters and setters
	int getId() const;
	char* getName() const;
	int getYearOfBirth() const;
	int getGender() const;
	void setName(char* name);
	void setYearOfBirth(int year);
	void setGender(int gender);
	void setCurrDepartment(Department* dep);

	//methods
	void show() const;
	void addVisit(Visit* newVisit);

private:
	int id;
	char* name;
	int yearOfBirth;
	int gender;
	Department* curr_deparement;
	Visit** arr_of_visitations;
	int num_of_visitations;
};

#endif
