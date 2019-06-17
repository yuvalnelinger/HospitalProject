#include "department.h"

//c'tor and d'tor
Department::Department(string name) 
{
	setName(name);
}

//getters and setters
int Department::getNumOfStaffMembers()  { return staff_members.arrSize(); }

string Department::getName() const { return name; }

void Department::setName(string name)
{
	this->name = name;
}

//operators
const Department& Department::operator+=(const StaffMember* mem)
{	
	staff_members += (StaffMember*)mem;
	return *this;
}

//methods
void Department::addPatient(const Patient* patient)
{
	patients.push_back((Patient*)patient);
}

void Department::showPatients() const
{
	cout << "List Of Patints: " << endl;
	if (patients.size() == 0)
	{
		cout << "No patients yet." << endl;
	}
	else
	{
		for (int i = 0; i < patients.size(); i++)
			cout << this->patients[i]->getName().c_str() << " , ID " << this->patients[i]->getId() << endl;
	}
}

void Department::showStaff() 
{
	cout << "This is department " << name.c_str();
	cout << " with the following staff members: " << endl;
	if (staff_members.arrSize() == 0)
	{
		cout << "No staff members yet." << endl;
	}
	else
	{
		for (int i = 0; i < staff_members.arrSize(); i++)
		{
			cout << this->staff_members[i]->getName().c_str() << ", ID " << this->staff_members[i]->getId() << endl;
		}
	}
}

void Department::printNamesOfStaffToFile(ofstream &out)
{
	int size = staff_members.arrSize();
	for (int i = 0; i < size; i++)
	{
		out << staff_members[i]->getName().c_str() << " ";
	}
}
