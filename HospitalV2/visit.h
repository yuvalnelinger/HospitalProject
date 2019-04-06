#ifndef __VISIT_H
#define __VISIT_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Date.h"
class Patient;
class Doctor;
class Nurse;

class Visit
{
private:
	Date dateOfArrival;
	Patient* patient;
	char* visitPurpose;
	Doctor* treatDoc;
	Nurse* treatNurse;

public:
	//c'tor
	Visit(Patient* patient, Date date, char* purpose, Doctor* doc, Nurse* nurse);

	//copy c'tor
	Visit(const Visit& other);

	//setters and getters
	char* getVisitPurpose() const;
	void setVisitPurpose(const char* purpose);
};

#endif