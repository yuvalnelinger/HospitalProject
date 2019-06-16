#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#define _CRT_SECURE_NO_WARNINGS
#define INIT_SIZE 50
#include "doctor.h"
#include "Nurse.h"
#include "patient.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "Array.h"

using namespace std;

class Department
{
private:
	string name;
	Array<StaffMember*> staff_members;
	vector<Patient*> patients;


public:
	//c'tor and d'tor
	Department(string name);
	~Department();

	//getters and setters
	int getNumOfStaffMembers();
	string getName() const;
	void setName(string name);

	//operators
	const Department& operator+=(const StaffMember* mem);

	//methods
	void addStaffMember(const StaffMember* mem);
	void addPatient(const Patient* patient);
	void showPatients() const;
	void showStaff();
	void printNamesOfStaff(ofstream &out);

private:
	//copy c'tor
	Department(const Department&); //prevent from user to make a copy of department
};

#endif
