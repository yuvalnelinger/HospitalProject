#ifndef __NURSE_H
#define __NURSE_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Department;

class Nurse
{
private:
	static int counter; //unique id, starts from: 2000
	int id;
	char* name;
	int years_of_experience;
	Department* department;

public:
	//c'tor and d'tor
	Nurse(char* name, int y_exp, Department* depart);
	~Nurse();

	//getters and setters
	int getId();
	char* getName() const;
	int getYearsOfExperience() const;
	void setName(char* name);
	void setYearsOfExperience(int years);
	void setDepartment(Department* depart);

	//methods
	void show() const;

};

#endif
