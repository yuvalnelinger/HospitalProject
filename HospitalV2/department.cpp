#include "department.h"
#include "doctor.h"
#define NOT_FOUND -1

Department::Department()
{
	cout << "In Department c'tor" << endl;
	doctors = new Doctor*[10];
	num_of_doctors = 0;
	patients = new Patient*[10];
	num_of_patients = 0;

	name = 0;
}

Department::Department(Doctor** doctors_arr, Patient** patients_arr, int size, int size_pat, char* newName)
{
	cout << "In Department c'tor" << endl;
	doctors = doctors_arr;
	patients = patients_arr;
	num_of_doctors = size;
	num_of_patients = size_pat;

	name = newName;
}

Department::~Department()
{
	cout << "In d'tor of Research Institute" << endl;
	delete[] doctors;
}

//getters
int Department::getNumOfDoctors() const { return num_of_doctors; }
char* Department::getDepName() const { return name; }

//methods
void Department::addDoctor(Doctor* doctor)
{
	doctors[num_of_doctors++] = doctor;
}

void Department::addPatient(Patient* patient)
{
	patients[num_of_patients++] = patient;
}

void Department::setName(char* newName)
{
	name = newName;
}
void Department::showPatients() const
{
	cout << "List Of Patints: " << endl;
	for (int i = 0; i < num_of_patients; i++)
	{
		cout << patients[i]->getPatientName() << endl;
	}
}
void Department::show() const {
	cout << "This is department " << name << " with the following doctors: " << endl;
	for (int i = 0; i < num_of_doctors; i++)
	{
		cout << doctors[i]->getName() << endl;
	}
	cout << "And Patients: " << endl;
	for (int i = 0; i < num_of_patients; i++)
	{
		cout << patients[i]->getPatientName() << endl;
	}
}


