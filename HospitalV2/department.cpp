#include "department.h"

//c'tor and d'tor
Department::Department(const char* name) : name(nullptr), size_of_stf_mem(INIT_SIZE), size_of_patients(INIT_SIZE)
{
	setName(name);
	staff_members = new StaffMember*[size_of_stf_mem];
	num_of_stf_mem = 0;
	patients = new Patient*[size_of_patients];
	num_of_patients = 0;
}

Department::~Department()
{
	delete[] name;
	delete[]staff_members;
	delete[] patients;
}

//getters and setters
int Department::getNumOfStaffMembers() const { return num_of_stf_mem; }

char* Department::getName() const { return name; }

void Department::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

//operators
const Department& Department::operator+=(const StaffMember& mem)
{
	cout << "test" << endl;
	this->addStaffMember(&mem);
	return *this;
}

//methods
void Department::addStaffMember(const StaffMember* mem)
{
	if (num_of_stf_mem == size_of_stf_mem) //array increment if needed
	{
		size_of_stf_mem *= 2;
		StaffMember** temp = new StaffMember*[size_of_stf_mem];
		for (int i = 0; i < num_of_stf_mem; i++) //copy from old array to new array
			temp[i] = staff_members[i];
		delete[] staff_members;
		staff_members = temp;
	}
	staff_members[num_of_stf_mem++] = (StaffMember*)mem;
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
	cout << " with the following staff members: " << endl;
	if (num_of_stf_mem == 0)
	{
		cout << "No staff members yet." << endl;
	}
	else
	{
		for (int i = 0; i < num_of_stf_mem; i++)
			cout << this->staff_members[i]->getName() << " , ID " << this->staff_members[i]->getId() << endl;
	}

}