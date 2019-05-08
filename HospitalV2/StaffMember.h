#ifndef __STAFFMEMBER_H
#define __STAFFMEMBER_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Department;

class StaffMember
{
protected:
	int id;
	char* name;
	static int counter;


public:
	//c'tor and d'tor
	StaffMember(char* name);
	StaffMember(const StaffMember& other);
	~StaffMember();

	//getters and setters
	int getId();
	char* getName() const;
	void setName(char* name);

	//methods
	//void show();

};

#endif
