#include <iostream>
using namespace std;
//test as
#include "hospital.h"

Hospital::Hospital()
{
	doctors = new Doctor*[50];
	num_of_doctors = 0;
	departments = new Department*[50];
	num_of_departments = 0;
	patients = new Patient*[50];
	num_of_patients = 0;
	visits = new Visit*[50];
	num_of_visits = 0;
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
	cout << "Successfully added department to hospital" << endl;
}

void Hospital::addDoctorToHospital(Doctor* docToAdd)
{
	doctors[num_of_doctors++] = docToAdd;
	cout << "Successfully added doctor to hospital" << endl;
}

void Hospital::addVisitToHospital(Visit* visToAdd)
{
	visits[num_of_visits++] = visToAdd;
	cout << "Successfully added visit to hospital" << endl;
}

void Hospital::addPatientToHospital(Patient* patientToAdd)
{
	patients[num_of_patients++] = patientToAdd;
	cout << "Successfully added patient to hospital" << endl;
}



void Hospital::showDepartments() const
{
	for (int i = 0; i < num_of_departments; i++)
	{
		cout << i << ". " << departments[i]->getDepName() << endl;
	}
}

Department* Hospital::getDepartmentByIndex(int num) const
{
	return departments[num];
}

Patient* Hospital::getPatientByID(int id) const
{
	for (int i = 0; i < num_of_patients; i++)
	{
		if (patients[i]->getId() == id)
		{
			return patients[i];
		}
	}
	return 0;
}

Doctor* Hospital::getDoctorByID(int id) const
{
	for (int i = 0; i < num_of_doctors; i++)
	{
		if (doctors[i]->getEmpId() == id)
		{
			return doctors[i];
		}
	}
	return 0;
}


void Hospital::show() const
{
	cout << "List of doctors: \n";
	for (int i = 0; i < num_of_doctors; i++)
	{
		cout << doctors[i]->getName() << endl;
	}
	cout << "List of Departments: \n";
	for (int i = 0; i < num_of_departments; i++)
	{
		cout << departments[i]->getDepName() << endl;
	}
	cout << "List of Patients: \n";
	for (int i = 0; i < num_of_patients; i++)
	{
		cout << patients[i]->getPatientName() << endl;
	}

}