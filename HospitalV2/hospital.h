#ifndef __HOSPITAL_H
#define __HOSPITAL_H

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
	int num_of_departments;
	Research_Institute RI;
	Doctor** doctors;
	int num_of_doctors;
	Nurse** nurses;
	int num_of_nurses;
	Patient** patients;
	int num_of_patients;

public:
	//c'tor and d'tor
	Hospital();
	Hospital(Doctor** docs, int numDocs, Department** deps, int numDeps, Patient** patientList, int numPatients); //I don't think we will use it
	~Hospital();

	//getters and setters
	Department* getDepartmentByIndex(int num) const;
	Patient* getPatientByID(int id) const;
	Doctor* getDoctorByID(int id) const;

	//methods
	void addDepartment(Department* depToAdd);
	void addDoctor(Doctor* docToAdd);
	void addPatient(Patient* patientToAdd);
	void showDepartments() const;
	void show() const;

	//menu methods
	void mainMenu();
	void addStaffMemberMenu();     //Q2,Q3
	void patientsMenu();		   //Q4,Q7,Q10
	void researchInstituteMenu();  //Q5,Q6,Q9
};

#endif