#include "department.h"

//c'tor and d'tor
Department::Department(char* name) : name(nullptr), size_of_doctors(INIT_SIZE), size_of_nurses(INIT_SIZE), size_of_patients(INIT_SIZE)
{
	setName(name);
	doctors = new Doctor*[size_of_doctors];
	num_of_doctors = 0;
	nurses = new Nurse*[size_of_nurses];
	num_of_nurses = 0;
	patients = new Patient*[size_of_patients];
	num_of_patients = 0;
}

Department::~Department()
{
	delete[] name;
	delete[]doctors;
	delete[]nurses;
	delete[] patients;
}

//getters and setters
int Department::getNumOfDoctors() const { return num_of_doctors; }

int Department::getNumOfNurses() const { return num_of_nurses; }

char* Department::getDepName() const { return name; }

void Department::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

//methods
void Department::addDoctor(Doctor* doctor)
{
	if (num_of_doctors == size_of_doctors) //array increment if needed
	{
		size_of_doctors *= 2;
		Doctor** temp = new Doctor*[size_of_doctors];
		for (int i = 0; i < num_of_doctors; i++) //copy from old array to new array
			temp[i] = doctors[i];
		delete[] doctors;
		doctors = temp;
	}
	doctors[num_of_doctors++] = doctor;
}

void Department::addNurse(Nurse* nurse)
{
	if (num_of_nurses == size_of_nurses) //array increment if needed
	{
		size_of_nurses *= 2;
		Nurse** temp = new Nurse*[size_of_nurses];
		for (int i = 0; i < num_of_nurses; i++) //copy from old array to new array
			temp[i] = nurses[i];
		delete[] nurses;
		nurses = temp;
	}
	nurses[num_of_nurses++] = nurse;
}

void Department::addPatient(Patient* patient)
{
	if (num_of_patients == size_of_patients) //array increment if needed
	{
		size_of_patients *= 2;
		Patient** temp = new Patient*[size_of_patients];
		for (int i = 0; i < num_of_patients; i++) //copy from old array to new array
			temp[i] = patients[i];
		delete[] patients;
		patients = temp;
	}
	patients[num_of_patients++] = patient;
}

void Department::showPatients() const
{
	cout << "List Of Patints: " << endl;
	if (num_of_patients == 0)
	{
		cout << "No patients yet." << endl;
	}
	else
	{
		for (int i = 0; i < num_of_patients; i++)
			cout << this->patients[i]->getName() << " , ID " << this->patients[i]->getId() << endl;
	}
}

void Department::showStaff() const 
{
	cout << "This is department " << name;
	cout << " with the following doctors: " << endl;
	if (num_of_doctors == 0)
	{
		cout << "No doctors yet." << endl;
	}
	else
	{
		for (int i = 0; i < num_of_doctors; i++)
			cout << this->doctors[i]->getName() << " , ID " << this->doctors[i]->getId() << endl;
	}

	cout << "And Nurses: " << endl;
	if (num_of_nurses == 0)
	{
		cout << "No nurses yet." << endl;
	}
	else
	{
		for (int i = 0; i < num_of_nurses; i++)
			cout << this->nurses[i]->getName() << " , ID " << this->nurses[i]->getId() << endl;
	}
}