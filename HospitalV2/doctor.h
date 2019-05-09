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
	Department* department;

public:
	//c'tor and d'tor
	Doctor(char* name, char* specialty, Department* depart);
	Doctor();
	Doctor(const Doctor& other);
	~Doctor();

	//getters and setters
	//int getId();
	//char* getName() const;
	char* getSpecialty() const;
	//void setName(char* name);
	void setSpecialty(char* specialty);
	Department* getDepartment() const;
	void setDepartment(Department* dep);

	//methods
	virtual void show();

};

#endif
