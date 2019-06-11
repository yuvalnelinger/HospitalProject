#include "StaffMember.h"
#include "department.h"
#include "Researcher.h"
#include <iostream>

int StaffMember::counter = 1000;

StaffMember::StaffMember(const char* name, Department* deparement) : name(nullptr)
{
	this->id = counter++;
	setName(name);
	this->department = deparement;
}

StaffMember::StaffMember(ifstream& inFile)
{
	inFile >> id >> name >> nullptr;
}

StaffMember::StaffMember(const StaffMember& other)
{
	*this = other;
}

StaffMember::StaffMember()
{
	this->id = counter++;
	setName(0);
	this->department = 0;
}

StaffMember::~StaffMember()
{
	delete[] name;
}

//getters and setters
int StaffMember::getId() { return id; }

char* StaffMember::getName() const { return name; }

Department* StaffMember::getDepartment() const { return department; }

char* StaffMember::getDepartmentName() const { return department->getName(); }

void StaffMember::setName(const char* name)
{
	if (this->name)
	{
		delete[] this->name;
	}
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

//operators
const StaffMember& StaffMember::operator=(const StaffMember& other)
{
	if (this != &other)
	{
		id = other.id;

		delete[]name;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);

		department = other.department;
	}
	return *this;
}

ostream& operator<<(ostream& os, const StaffMember& stf_mem)
{
	os << "ID: " << stf_mem.id << ", "
		<< "Type: " << typeid(stf_mem).name() + 6 <<
		", Name: " << stf_mem.name;
	if (stf_mem.department)		//researcher has no department
	{
		cout << ", Department: " << stf_mem.getDepartment()->getName();
	}
	
	stf_mem.toOs(os);
	return os;
}

void StaffMember::addArticle(Article* article) {} //method of an abstract class can not be reached

//methods
void StaffMember::show() const
{
	cout << "Id: " << id << ", "
		<< "Name: " << name;

	if (this->department)  //for the case of researcher that has no specipic department
	{
		cout << ", Department: " << department->getName();
	}
}

