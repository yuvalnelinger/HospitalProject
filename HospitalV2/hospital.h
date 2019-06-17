#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include "department.h"
#include "StaffMember.h"
#include "Nurse.h"   
#include "doctor.h"
#include "Research_Institute.h"
#include "patient.h"
#include "Surgeon.h"
#include "SurgeonResearcher.h"
#include "DoctorResearcher.h"
using namespace std;

class Hospital
{
private:
	string name;
	vector <Department*> departments;
	Research_Institute RI;
	vector <StaffMember*> staff_members;
	vector <Patient*> patients;

public:
	friend class Interface;

	//c'tor and d'tor
	Hospital(const string name);
	~Hospital();

	//getters and setters
	string getName() const;
	Department* getDepartmentByIndex(int num) const throw (const char*);  
	Patient* getPatientByID(int id) const throw (const char*);
	StaffMember* getStaffMemberByID(int id) const throw (const char*);
	int getNumOfDepartments();
	Research_Institute& getResearchInstitute();
	void setName(const string name);

	//methods
	void addDepartment(const string name);
	void addDoctor(const string name, const string docSpecialty, Department* assigned_dep,bool isSurgeon,bool isResearcher,int num_of_surgeries);
	void addNurse(const string name, int yearsExperience, Department* assigned_dep);
	void addPatient(Patient* patientToAdd);
	void addToRI(StaffMember* mem);
	void showDepartments() const;
	void showPatientById(int id) const;
	void showDocResearchers() const;
	void showStaff() const;
	void show() const;

private:
	Hospital(const Hospital&); //prevent from user to make a copy of the hospital
};

#endif