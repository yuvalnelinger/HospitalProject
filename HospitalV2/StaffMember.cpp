#include "StaffMember.h"
#include "department.h"
#include "Researcher.h"

int StaffMember::counter = 1000;

StaffMember::StaffMember(char* name, Department* deparement) : name(nullptr)
{
	cout << "In Staff Member c'tor..." << endl;
	cout << "test1" << endl;
	this->id = counter++;
	cout << "test2" << endl;
	setName(name);
	cout << "test3" << endl;
	this->department = deparement;
	cout << "test4" << endl;
}

StaffMember::StaffMember(const StaffMember& other)
{
	cout << "In StaffMember copy \n";
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
	cout << "In Staff Member d'tor..." << endl;
	delete[] name;
}

//getters and setters
int StaffMember::getId() { return id; }

char* StaffMember::getName() const { return name; }

void StaffMember::setName(char* name)
{
	cout << "setting name" << endl;
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

//operators
const StaffMember& StaffMember::operator=(const StaffMember& other)
{
	cout << "StaffMember::In operator=" << endl;
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

