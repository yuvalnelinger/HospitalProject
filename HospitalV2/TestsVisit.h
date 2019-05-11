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

class TestsVisit : public Visit
{
private:


public:
	//c'tor
	TestsVisit(Patient* patient, Date date, char* purpose, StaffMember* doc);

	//copy c'tor
	TestsVisit(const TestsVisit& other);

	//setters and getters

};

#endif