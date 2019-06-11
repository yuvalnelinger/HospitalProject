#include "doctor.h"

//c'tor and d'tor
Doctor::Doctor(const char* name, const char* specialty, Department* depart) : StaffMember(name, depart)
{
	setSpecialty(specialty);
}

Doctor::Doctor(ifstream& inFile) : StaffMember(inFile)
{
	inFile >> specialty;
}


Doctor::~Doctor()
{
	delete[] specialty;
}

//getters and setters
char* Doctor::getSpecialty() const { return specialty; }

void Doctor::setSpecialty(const char* specialty)
{
	if (this->specialty)
	{
		delete[] this->specialty;
	}
	if (specialty==0)
	{
		this->specialty = 0;
	}
	else
	{
		this->specialty = new char[strlen(specialty) + 1];
		strcpy(this->specialty, specialty);
	}
}

Department* Doctor::getDepartment() const
{
	return this->department;
}

//operators
const Doctor& Doctor::operator=(const Doctor& other)
{
	StaffMember::operator=(other);

	delete[]specialty;
	specialty = new char[strlen(other.specialty) + 1];
	strcpy(specialty, other.specialty);

	return *this;
}

void Doctor::toOs(ostream& os) const
{
	os << ", Specialty: " << specialty
		<< endl;
}

//methods
void Doctor::show() const
{
	StaffMember::show();
	cout << ", " << "Specialty: " << specialty;
}

Doctor::Doctor(const Doctor& other) : StaffMember(other)
{
	setSpecialty(other.specialty);
}