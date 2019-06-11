#ifndef __DOCTOR_H
#define __DOCTOR_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StaffMember.h"
using namespace std;

class Doctor : virtual public StaffMember
{
protected:
	String specialty;

public:
	//c'tor and d'tor
	Doctor(const char* name, const char* specialty, Department* depart);
	Doctor(ifstream& inFile);
	~Doctor();

	char* getSpecialty() const;
	void setSpecialty(const char* specialty);
	Department* getDepartment() const;

	//operators
	const Doctor& operator=(const Doctor& other);
	virtual void toOs(ostream& os) const override;
	friend istream& operator>> (istream& in, Doctor& d)
	{
		in >> d.specialty;
	}

	//methods
	virtual void show() const;

protected:
	Doctor(const Doctor& other); //prevent from the user making a copy of a doctor
};

#endif
