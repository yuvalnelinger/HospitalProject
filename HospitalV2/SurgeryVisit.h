#ifndef __SURGEVISIT_H
#define __SURGEVISIT_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Date.h"
#include "visit.h"
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
	SurgeryVisit(Patient* patient, Date date, char* purpose, Doctor* doc, Nurse* nurse,int roomNum,bool isFast);

	//copy c'tor
	SurgeryVisit(const SurgeryVisit& other);

	//setters and getters

};

#endif