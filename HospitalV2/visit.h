#ifndef __VISIT_H
#define __VISIT_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Date.h"
#include "StaffMember.h"

class Patient;
class Doctor;
class Nurse;

class Visit
{
private:
	Date dateOfArrival;
	Patient* patient;
	char* visitPurpose;
	bool isSurgery;
	StaffMember* treatDoc;

public:
	//c'tor
	Visit(Patient* patient, Date date, char* purpose, bool isSurgery,StaffMember* doc);
	Visit();

	//copy c'tor
	Visit(const Visit& other);

	//setters and getters
	char* getVisitPurpose() const;
	void setVisitPurpose(const char* purpose);
	bool getVisitType() const;
};

#endif