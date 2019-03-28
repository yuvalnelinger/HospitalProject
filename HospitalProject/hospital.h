#ifndef __HOSPITAL_H
#define __HOSPITAL_H

#include "doctor.h"
#include "department.h"
#include "patient.h"
#include "visit.h"

class Hospital
{
private:
	Doctor** doctors;
	int num_of_doctors;
	Department** departments;
	int num_of_departments;
	Patient** patients;
	int num_of_patients;
	Visit** visits;
	int num_of_visits;
public:
	//c'tor and d'tor
	Hospital();
	Hospital(Doctor** docs, int numDocs, Department** deps, int numDeps, Patient** patientList, int numPatients, Visit** vis, int numVis);
	~Hospital();

	//methods
	void addDepartmentToHospital(Department* depToAdd);
};

#endif