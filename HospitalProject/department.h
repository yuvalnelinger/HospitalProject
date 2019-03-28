#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include <iostream>
using namespace std;
#include "patient.h"
#include "doctor.h"

class Department
{
private:
	Doctor** doctors;
	Patient** patients;
	int num_of_doctors;
	int num_of_patients; 
	char* name;
	//add here nurses too
public:
	//c'tor and d'tor
	Department();
	Department(Doctor** doctors_arr, Patient** patients_arr, int size, int size_pat, char* newName);
	~Department();

	//getters
	int getNumOfDoctors() const;
	char* getDepName() const;

	//methods
	void addDoctor(Doctor* doctor); //adds doctor ptr to the array
	void setName(char* newName);
	void showPatients() const;
	void show() const;
};

#endif
