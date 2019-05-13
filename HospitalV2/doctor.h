#ifndef __DOCTOR_H
#define __DOCTOR_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StaffMember.h"
using namespace std;

class Doctor : virtual public StaffMember
{
protected:
	char* specialty;

public:
	//c'tor and d'tor
	Doctor(const char* name, const char* specialty, Department* depart);
	Doctor();
	Doctor(const Doctor& other);
	~Doctor();

	//getters and setters
	//int getId();
	//char* getName() const;
	char* getSpecialty() const;
	//void setName(char* name);
	void setSpecialty(const char* specialty);
	Department* getDepartment() const;
	//void setDepartment(Department* dep);

	//operators
	const Doctor& operator=(const Doctor& other);

	//methods
	virtual void show() const;

};

#endif
