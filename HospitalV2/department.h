#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#define _CRT_SECURE_NO_WARNINGS
#define INIT_SIZE 50
#include "doctor.h"
#include "Nurse.h"
#include "patient.h"
#include <iostream>
using namespace std;

class Department
{
private:
	char* name;
	Doctor** doctors;
	int size_of_doctors;
	int num_of_doctors;
	Nurse** nurses;
	int size_of_nurses;
	int num_of_nurses;
	Patient** patients;
	int size_of_patients;
	int num_of_patients;

public:
	//c'tor and d'tor
	Department(char* name);
	~Department();

	//getters and setters
	int getNumOfDoctors() const;
	int getNumOfNurses() const;
	char* getDepName() const;
	void setName(const char* name);

	//methods
	void addDoctor(Doctor* doctor);
	void addNurse(Nurse* nurse);
	void addPatient(Patient* patient);
	void showPatients() const;
	void showStaff() const;

private:
	//copy c'tor
	Department(const Department&); //prevent from user to make a copy of department
};

#endif
