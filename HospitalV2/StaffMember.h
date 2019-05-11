#ifndef __STAFFMEMBER_H
#define __STAFFMEMBER_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Department;

//abstract class
class StaffMember
{
protected:
	int id;
	char* name;
	Department* department;
	static int counter;


public:
	//c'tor and d'tor
	StaffMember(char* name, Department* department);
	StaffMember(const StaffMember& other);
	StaffMember();
	virtual ~StaffMember();

	//getters and setters
	int getId();
	char* getName() const;
	void setName(char* name);

	//methods
	virtual void setDepartment(Department* depart) { department = depart; }
	virtual void show() const = 0;

};

#endif
