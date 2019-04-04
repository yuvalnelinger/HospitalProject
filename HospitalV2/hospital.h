#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#define MAX_TITLE 150
#define MAX_NAME 30
#define INIT_SIZE 50
#define NOT_FOUND -1

#include <iostream>
using namespace std;
#include "department.h"
#include "Nurse.h"   
#include "doctor.h"
#include "Research_Institute.h"
#include "patient.h"


class Hospital
{
private:
	Department** departments;
	int size_of_departments = INIT_SIZE;
	int num_of_departments;
	Research_Institute RI;
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
	Hospital();
	~Hospital();

	//getters and setters
	Department* getDepartmentByIndex(int num) const;
	Patient* getPatientByID(int id) const;
	Doctor* getDoctorByID(int id) const;
	int getNumOfDepartments();
	Research_Institute& getResearchInstitute();

	//methods
	void addDepartment(char* name);
	void addDoctor(char* name, char* docSpecialty, Department* assigned_dep);
	void addNurse(char* name, int yearsExperience, Department* assigned_dep);
	void addPatient(Patient* patientToAdd);
	void showDepartments() const;
	void showPatientById(int id) const;
	void showStaff() const;
	void show() const;
};

#endif