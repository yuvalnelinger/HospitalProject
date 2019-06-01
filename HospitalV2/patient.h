#ifndef __PATIENT_H
#define __PATIENT_H

#define _CRT_SECURE_NO_WARNINGS
#define INIT_SIZE 50
#include <iostream>
#include "visit.h"
#include "StaffMember.h"
#include "doctor.h"
#include "Nurse.h"
#include "SurgeryVisit.h"
#include "TestsVisit.h"
#include <vector>
using namespace std;

class Department;

class Patient
{
public:
	enum eGender { MALE, FEMALE };

	//c'tor and d'tor
	Patient(char* name, int id, int year, int gender);
	~Patient();

	//getters and setters
	int getId() const;
	char* getName() const;
	int getYearOfBirth() const;
	int getGender() const;
	Department* getCurrentDepartment() const;
	void setName(char* name);
	void setYearOfBirth(int year);
	void setGender(int gender);
	void setCurrDepartment(Department* dep);

	//methods
	void show() const;
	void addVisit(Patient* patient, Date visitDate ,StaffMember* treatDoc,char* purpose,bool* isFast, int roomNum, bool* isSurgery);
	bool getLastVisitType();
	Visit* getLastVisit();

private:
	int id;
	char* name;
	int yearOfBirth;
	int gender;
	Department* curr_department;
	vector<Visit*> visitations;
	//int size_of_visitations;
	//int num_of_visitations;

private:
	//copy c'tor
	Patient(const Patient&); //prevent from user to make a copy of patient
};

#endif
