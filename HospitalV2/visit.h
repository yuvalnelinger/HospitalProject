#ifndef __VISIT_H
#define __VISIT_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"
#include "StaffMember.h"
using namespace std;

class Patient;
class Doctor;
class Nurse;

class Visit
{
private:
	Date dateOfArrival;
	Patient* patient;
	string visitPurpose;
	bool isSurgery;
	StaffMember* treatDoc;

public:
	//c'tor
	Visit(Patient* patient, Date date, string purpose, bool isSurgery,StaffMember* doc);
	Visit();

	//copy c'tor
	Visit(const Visit& other);

	//setters and getters
	string getVisitPurpose() const;
	void setVisitPurpose(const string purpose);
	bool getVisitType() const;
};

#endif