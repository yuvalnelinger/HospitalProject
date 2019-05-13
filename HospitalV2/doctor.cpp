#include "doctor.h"

//c'tor and d'tor
Doctor::Doctor(const char* name, const char* specialty, Department* depart) : StaffMember(name, depart), specialty(nullptr)
{
	cout << "test5" << endl;
	cout << "In Doctor c'tor..." << endl;
	cout << "test6" << endl;
	setSpecialty(specialty);
	cout << "test7" << endl;

}

//why we need default??? - (Yuval) we don't, it was added to solve compilation error, we will remove once we have something working :)
//(Sharon) ahla! :)
Doctor::Doctor() : StaffMember(name, nullptr)
{
	cout << "In Doctor default c'tor..." << endl;
	setSpecialty(0);
	this->department = 0;
}

Doctor::Doctor(const Doctor& other) : StaffMember(other)
{
	cout << "In Doctor::Doctor(copy)\n";
	setSpecialty(other.specialty);
	//*this = other;
}

Doctor::~Doctor()
{
	cout << "In Docctor d'tor..." << endl;
	delete[] specialty;
}

//getters and setters
//int Doctor::getId() { return id; }
//char* Doctor::getName() const { return name; }

//void Doctor::setName(char* name)
//{
//	delete[] this->name;
//	this->name = new char[strlen(name) + 1];
//	strcpy(this->name, name);
//}

char* Doctor::getSpecialty() const { return specialty; }

void Doctor::setSpecialty(const char* specialty)
{
	delete[] this->specialty;
	this->specialty = new char[strlen(specialty) + 1];
	strcpy(this->specialty, specialty);
}

/*void Doctor::setDepartment(Department* dep)
{
	department = dep;
}*/

Department* Doctor::getDepartment() const
{
	return this->department;
}

//operators
const Doctor& Doctor::operator=(const Doctor& other)
{
	cout << "In Doctor::operator=" << endl;
	StaffMember::operator=(other);

	delete[]specialty;
	specialty = new char[strlen(other.specialty) + 1];
	strcpy(specialty, other.specialty);

	return *this;
}


//methods
void Doctor::show() const
{
	StaffMember::show();
	cout << ", " << "Specialty: " << specialty;
}