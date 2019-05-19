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
	StaffMember** staff_members;
	int size_of_stf_mem;
	int num_of_stf_mem;
	Patient** patients;
	int size_of_patients;
	int num_of_patients;

public:
	//c'tor and d'tor
	Department(const char* name);
	~Department();

	//getters and setters
	int getNumOfStaffMembers() const;
	char* getName() const;
	void setName(const char* name);

	//operators
	const Department& operator+=(const StaffMember& mem);

	//methods
	void addStaffMember(const StaffMember* mem);
	void addPatient(Patient* patient);
	void showPatients() const;
	void showStaff() const;

private:
	//copy c'tor
	Department(const Department&); //prevent from user to make a copy of department
};

#endif
