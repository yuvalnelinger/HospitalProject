#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#define MAX_TITLE 150
#define MAX_NAME 30
#define INIT_SIZE 50
#define NOT_FOUND -1
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
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
	char* name;
	Department** departments;
	int size_of_departments;
	int num_of_departments;
	Research_Institute RI;
	StaffMember** staff_members;
	int size_of_stf_mem;
	int num_of_stf_mem;
	Patient** patients;
	int size_of_patients;
	int num_of_patients;

public:
	//c'tor and d'tor
	Hospital(const char* name);
	~Hospital();

	//getters and setters
	char* getName() const;
	Department* getDepartmentByIndex(int num) const;
	Patient* getPatientByID(int id) const;
	StaffMember* getStaffMemberByID(int id) const;
	//Nurse* getNurseByID(int id) const; OLD
	int getNumOfDepartments();
	Research_Institute& getResearchInstitute();
	void setName(const char* name);

	//methods
	void addDepartment(const char* name);
	void addDoctor(const char* name, const char* docSpecialty, Department* assigned_dep,bool isSurgeon,bool isResearcher,int num_of_surgeries);
	void addNurse(const char* name, int yearsExperience, Department* assigned_dep);
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