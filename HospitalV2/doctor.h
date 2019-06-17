#ifndef __DOCTOR_H
#define __DOCTOR_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StaffMember.h"
using namespace std;

class Doctor : virtual public StaffMember
{
protected:
	string specialty;

public:
	//c'tor
	Doctor(const string name, const string specialty, Department* depart);

	string getSpecialty() const;
	void setSpecialty(const string specialty);
	Department* getDepartment() const;

	//operators
	const Doctor& operator=(const Doctor& other);
	virtual void toOs(ostream& os) const override;

	//methods
	virtual void show() const;

protected:
	Doctor(const Doctor& other); //prevent from the user making a copy of a doctor
};

#endif
