#include "StaffMember.h"
#include "department.h"
#include "Researcher.h"
#include <iostream>

int StaffMember::counter = 1000;

StaffMember::StaffMember(const string name, Department* deparement) 
{
	this->id = counter++;
	setName(name);
	this->department = deparement;
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

StaffMember::~StaffMember() {}

//getters and setters
int StaffMember::getIDCounter() { return counter; }

int StaffMember::getId() const { return id; }

string StaffMember::getName() const { return name; }

Department* StaffMember::getDepartment() const { return department; }

string StaffMember::getDepartmentName() const { return department->getName(); }

void StaffMember::setName(const string name)
{
	this->name = name;
}

//operators
const StaffMember& StaffMember::operator=(const StaffMember& other)
{
	if (this != &other)
	{
		id = other.id;

		this->name = other.name;

		department = other.department;
	}
	return *this;
}

ostream& operator<<(ostream& os, const StaffMember& stf_mem)
{
	os << "ID: " << stf_mem.id << ", "
		<< "Type: " << typeid(stf_mem).name() + 6 <<
		", Name: " << stf_mem.name.c_str();
	if (stf_mem.department)		//researcher has no department
	{
		cout << ", Department: " << stf_mem.getDepartment()->getName().c_str();
	}
	
	stf_mem.toOs(os);
	return os;
}

void StaffMember::addArticle(Article* article) {} //method of an abstract class can not be reached

//methods
void StaffMember::show() const
{
	cout << "Id: " << id << ", "
		<< "Name: " << name.c_str();

	if (this->department)  //for the case of researcher that has no specipic department
	{
		cout << ", Department: " << department->getName().c_str();
	}
}

