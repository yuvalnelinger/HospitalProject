#include "department.h"

Department::Department()
{
	cout << "In Department c'tor..." << endl;
	doctors = new Doctor*[10];
	num_of_doctors = 0;
	nurses = new Nurse*[10];
	num_of_nurses = 0;
	patients = new Patient*[10];
	num_of_patients = 0;
}

//I don't think we will use it
Department::Department(Doctor** doctors_arr, Patient** patients_arr, int size, int size_pat, char* newName)
{
	cout << "In Department c'tor..." << endl;
	doctors = doctors_arr;
	patients = patients_arr;
	num_of_doctors = size;
	num_of_patients = size_pat;

	name = newName;
}

Department::~Department()
{
	cout << "In Department c'tor..." << endl;
	delete[]doctors;
	delete[]nurses;
	delete[] patients;
}

//getters and setters
int Department::getNumOfDoctors() const { return num_of_doctors; }

char* Department::getDepName() const { return name; }

void Department::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

//methods
void Department::addDoctor(Doctor* doctor)
{
	doctors[num_of_doctors++] = doctor;
}

void Department::addNurse(Nurse* nurse)
{
	nurses[num_of_nurses++] = nurse;
}


void Department::addPatient(Patient* patient)
{
	patients[num_of_patients++] = patient;
}

void Department::showPatients() const
{
	cout << "List Of Patints: " << endl;
	for (int i = 0; i < num_of_patients; i++)
	{
		cout << patients[i]->getName() << endl;
	}
}
void Department::show() const {
	cout << "This is department " << name;
	cout << " with the following doctors: " << endl;
	for (int i = 0; i < num_of_doctors; i++)
	{
		cout << doctors[i]->getName() << endl;
	}
	cout << "And Patients: " << endl;
	for (int i = 0; i < num_of_patients; i++)
	{
		cout << patients[i]->getName() << endl;
	}
}


