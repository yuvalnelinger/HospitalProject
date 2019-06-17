#include "patient.h"

Patient::Patient(string name, int id, int year, int gender) : curr_department(nullptr)
{
	this->id = id;
	setName(name);
	this->yearOfBirth = year;
	this->gender = gender;
}

Patient::~Patient()
{
	for (int i = 0; i < visitations.size(); i++)
		delete visitations[i];
}

//getters and setters
int Patient::getId() const { return id; }

string Patient::getName() const { return name; }

int Patient::getYearOfBirth() const { return yearOfBirth; }

int Patient::getGender() const { return gender; }

Department* Patient::getCurrentDepartment() const
{
	return curr_department;
}

void Patient::setName(string name)
{
	this->name = name;
}

void Patient::setYearOfBirth(int year)
{
	this->yearOfBirth = year;
}

void Patient::setGender(int gender)
{
	this->gender = gender;
}

void Patient::setCurrDepartment(Department* dep)
{
	this->curr_department = dep;
}


//methods
void Patient::show() const
{
	cout << "Patient Name: " << name.c_str() << " Id: " << id << " Year Of Birth: " << " Gender: " << gender << endl;
}

void Patient::addVisit(Patient* patient, Date visitDate, StaffMember* treatDoc,string purpose, bool* isFast, int roomNum,bool* isSurgery)
{
	Visit* newVis;
	
	if (*isSurgery)
	{
		newVis = new SurgeryVisit(patient, visitDate, purpose, treatDoc, roomNum, *isFast);
	}
	else
	{
		newVis = new Visit(patient,visitDate,purpose,false,treatDoc);
	}
	visitations.push_back(newVis); //add new visit to this patient
}

bool Patient::getLastVisitType()
{
	return this->visitations[visitations.size()-1]->getVisitType();
}

Visit* Patient::getLastVisit()
{
	return this->visitations[visitations.size()-1];
}

