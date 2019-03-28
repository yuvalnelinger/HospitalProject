#ifndef __DOCTOR_H
#define __DOCTOR_H

#include <iostream>
using namespace std;

class Doctor
{
private:
	int employeeId;
	char* name;
	char* specialty;
public:
	//c'tor and d'tor
	Doctor(int newId, char* newName, char* newSpecialty);
	~Doctor();

	//getters
	int getEmpId();
	char* getName() const;
	char* getSpecialty() const;

	//setters
	void setEmpId(int newId);
	void setNamee(char* newName);
	void setSpecialty(char* newSpecialty);

	//methods
	void show();


};

#endif
