#ifndef __SURGEVISIT_H
#define __SURGEVISIT_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"
#include "visit.h"
using namespace std;
class Patient;
class Doctor;
class Nurse;

class SurgeryVisit : public Visit
{
private:
	int roomNum;
	bool isFast;

public:
	//c'tor
	SurgeryVisit(Patient* patient, Date date, string purpose, StaffMember* doc,int roomNum,bool isFast);

	//setters and getters
	int getRoomNum();
	bool getIsFast();

private:
	//copy c'tor
	SurgeryVisit(const SurgeryVisit& other);
};

#endif