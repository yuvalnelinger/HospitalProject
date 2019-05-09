#include "StaffMember.h"
#include "department.h"
#include "Researcher.h"

int StaffMember::counter = 1000;

StaffMember::StaffMember(char* name, Department* deparement) : name(nullptr)
{
	cout << "In Staff Member c'tor..." << endl;
	this->id = counter++;
	setName(name);
	this->department = deparement;
}

StaffMember::StaffMember(const StaffMember& other)
{
	cout << "In StaffMember copy \n";
	*this = other;
}
StaffMember::~StaffMember()
{
	cout << "In Staff Member d'tor..." << endl;
	delete[] name;
}

//getters and setters
int StaffMember::getId() { return id; }
char* StaffMember::getName() const { return name; }

void StaffMember::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

//methods
void StaffMember::show() const
{

	cout << "Id: " << id << ", "
		<< "Name: " << name;

	if (this->department)  //for the case of researcher that has no specipic department
	{
		cout << " , Department: " << department->getName();
	}
}

