#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#define _CRT_SECURE_NO_WARNINGS
#include "doctor.h"
#include "Nurse.h"
#include "patient.h"
#include <iostream>
using namespace std;
#define INIT_SIZE 50

class Department
{
private:
	char* name;
	Doctor** doctors;
	int size_of_doctors = INIT_SIZE;
	int num_of_doctors;
	Nurse** nurses;
	int size_of_nurses = INIT_SIZE;
	int num_of_nurses;
	Patient** patients;
	int size_of_patients = INIT_SIZE;
	int num_of_patients;

public:
	//c'tor and d'tor
	Department(char* name);
	~Department();

	//getters and setters
	int getNumOfDoctors() const;
	char* getDepName() const;
	void setName(char* name);

	//methods
	void addDoctor(Doctor* doctor);
	void addNurse(Nurse* nurse);
	void addPatient(Patient* patient);
	void showPatients() const;
	void show() const;
};

#endif
