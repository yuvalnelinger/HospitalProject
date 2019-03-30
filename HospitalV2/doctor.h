#ifndef __DOCTOR_H
#define __DOCTOR_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//#include "department.h"
class Department;

class Doctor
{
public:
	//enum class eSpecialty {SURGEON, ASSISTANT, ANESTHESIOLOGIST};

	//c'tor and d'tor
	Doctor(char* newName, char* newSpecialty);
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
	static int counter; //unique id 
	int id;
	char* name;
	char* specialty;
	Department* department;
};

#endif
