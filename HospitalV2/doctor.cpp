#include "doctor.h"

//c'tor and d'tor
Doctor::Doctor(const string name, const string specialty, Department* depart) : StaffMember(name, depart)
{
	setSpecialty(specialty);
}

//getters and setters
string Doctor::getSpecialty() const { return specialty; }

void Doctor::setSpecialty(const string specialty)
{
	this->specialty = specialty;
}

Department* Doctor::getDepartment() const
{
	return this->department;
}

//operators
const Doctor& Doctor::operator=(const Doctor& other)
{
	StaffMember::operator=(other);
	specialty = other.specialty;
	return *this;
}

void Doctor::toOs(ostream& os) const
{
	os << ", Specialty: " << specialty.c_str()
		<< endl;
}

//methods
void Doctor::show() const
{
	StaffMember::show();
	cout << ", " << "Specialty: " << specialty.c_str();
}

Doctor::Doctor(const Doctor& other) : StaffMember(other)
{
	setSpecialty(other.specialty);
}