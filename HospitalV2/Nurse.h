#ifndef __NURSE_H
#define __NURSE_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StaffMember.h"
using namespace std;

class Department;

class Nurse : public StaffMember
{
private:
	int years_of_experience;
	Department* department;

public:
	//c'tor and d'tor
	Nurse(char* name, int y_exp, Department* depart);
	~Nurse();

	//getters and setters
//	int getId();
//	char* getName() const;
	int getYearsOfExperience() const;
//	void setName(char* name);
	void setYearsOfExperience(int years);
	virtual void setDepartment(Department* depart);

	//methods
	virtual void show() const;

private:
	Nurse(const Nurse&); //prevent from user to make a copy of nurse
};

#endif
