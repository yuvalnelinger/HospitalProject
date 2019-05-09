#ifndef __DOCTOR_H
#define __DOCTOR_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Department;

class Doctor
{
private:
	static int counter; //unique id 
	int id;
	char* name;
	char* specialty;
	Department* department;

public:
	//c'tor and d'tor
	Doctor(char* name, char* specialty, Department* depart);
	~Doctor();

	//getters and setters
	int getId();
	char* getName() const;
	char* getSpecialty() const;
	void setName(char* name);
	void setSpecialty(char* specialty);
	void setDepartment(Department* dep);

	//methods
	void show();

private:
	//copy c'tor
	Doctor(const Doctor&); //prevent from user to make a copy of doctor
};

#endif
