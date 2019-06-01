#include "patient.h"

Patient::Patient(char* name, int id, int year, int gender) : name(nullptr), curr_department(nullptr)
{
	this->id = id;
	setName(name);
	this->yearOfBirth = year;
	this->gender = gender;
	//arr_of_visitations = new Visit*[size_of_visitations];
	//num_of_visitations = 0;
}

Patient::~Patient()
{
	delete[]name;

	for (int i = 0; i < visitations.size(); i++)
		delete visitations[i];
}

//getters and setters
int Patient::getId() const { return id; }

char* Patient::getName() const { return name; }

int Patient::getYearOfBirth() const { return yearOfBirth; }

int Patient::getGender() const { return gender; }

Department* Patient::getCurrentDepartment() const
{
	return curr_department;
}

void Patient::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
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
	cout << "Patient Name: " << name << " Id: " << id << " Year Of Birth: " << " Gender: " << gender << endl;
}

void Patient::addVisit(Patient* patient, Date visitDate, StaffMember* treatDoc,char* purpose, bool* isFast, int roomNum,bool* isSurgery)
{
	//if (num_of_visitations == size_of_visitations) //array increment if needed
	//{
	//	size_of_visitations *= 2;
	//	Visit** temp = new Visit*[size_of_visitations];
	//	for (int i = 0; i < num_of_visitations; i++) //copy from old array to new array
	//		temp[i] = visitations[i];
	//	delete[] visitations;
	//	visitations = temp;
	//}
	Visit* newVis;
	
	if (*isSurgery)
	{
		newVis = new SurgeryVisit(patient, visitDate, purpose, treatDoc, roomNum, *isFast);
	}
	else
	{
		newVis = new Visit(patient,visitDate,purpose,false,treatDoc);
	}
	//this->visitations[num_of_visitations++] = newVis; 
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

