#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#define _CRT_SECURE_NO_WARNINGS
#include "doctor.h"
#include "Nurse.h"
#include "patient.h"

//class Nurse;

#include <iostream>
using namespace std;

class Department
{
private:
	char* name;
	Doctor** doctors;
	int num_of_doctors;
	Nurse** nurses;
	int num_of_nurses;
	Patient** patients;
	int num_of_patients;

public:
	//c'tor and d'tor
	Department();
	Department(Doctor** doctors_arr, Patient** patients_arr, int size, int size_pat, char* newName); //I don't think we will use it
	~Department();

	//getters and setters
	int getNumOfDoctors() const;
	char* getDepName() const;
	void setName(char* name);

	//methods
	void addDoctor(Doctor* doctor); //adds doctor ptr to the array
	void addNurse(Nurse* nurse);
	void addPatient(Patient* patient);
	void showPatients() const;
	void show() const;
};

#endif
