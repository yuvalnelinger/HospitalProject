#ifndef __STAFFMEMBER_H
#define __STAFFMEMBER_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Article.h"
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
	StaffMember(const char* name, Department* department);
	StaffMember(const StaffMember& other);
	StaffMember();
	virtual ~StaffMember();

	//getters and setters
	int getId();
	char* getName() const;
	Department* getDepartment() const;
	void setName(const char* name);

	//operators
	const StaffMember& operator=(const StaffMember& other);
	friend ostream& operator<<(ostream& os, const StaffMember& stf_mem);
	virtual void toOs(ostream& os) const = 0;

	//methods
	virtual void addArticle(Article* article);
	virtual void setDepartment(Department* depart) { department = depart; }
	virtual void show() const =0;

	////files methods
	//friend ostream& operator<<(ostream& out, const Department& d)
	//{
	//	if (typeid(out) == typeid(ofstream))
	//	{
	//		//save to file:
	//		//name of department, names of assigned staff members
	//		//and names of assigned patients

	//		out << "Dep: ";
	//		out << d.name << ",";

	//		out << "Staff: ";
	//		for (int i = 0; i < d.staff_members.size(); i++)
	//		{
	//			out << d.staff_members[i]->getName() << ",";
	//		}

	//		out << "Patients: ";
	//		for (int i = 0; i < d.patients.size(); i++)
	//		{
	//			out << d.patients[i]->getName() << ",";
	//		}
	//	}

	//	else //(typeid(out) == typeid(ostream))
	//	{
	//		//qq-to fill in print to screen
	//	}
	//}
};

#endif
