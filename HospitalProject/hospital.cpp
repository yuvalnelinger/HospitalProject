#include <iostream>
using namespace std;

#include "hospital.h"

Hospital::Hospital()
{
	doctors= new Doctor*[50];
	num_of_doctors=0;
	departments= new Department*[50];
	num_of_departments=0;
	patients= new Patient*[50];
	num_of_patients=0;
	visits=new Visit*[50];
	num_of_visits=0;
}
Hospital::Hospital(Doctor** docs, int numDocs, Department** deps, int numDeps, Patient** patientList, int numPatients, Visit** vis, int numVis)
{
	doctors = docs;
	num_of_doctors = numDocs;
	departments = deps;
	num_of_departments = numDeps;
	patients = patientList;
	num_of_patients = numPatients;
	visits = vis;
	num_of_visits = numVis;
}
Hospital::~Hospital()
{
	delete[]doctors;
	delete[]departments;
	delete[]patients;
	delete[]visits;
}

//methods
void Hospital::addDepartmentToHospital(Department* depToAdd)
{
	departments[num_of_departments++] = depToAdd;
}