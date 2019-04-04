#ifndef __VISIT_H
#define __VISIT_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Date;
class Patient;
class Doctor;

class Visit
{
private:
	Date* dateOfArrival;
	Patient* patient;
	char* visitPurpose;
	Doctor* treatDoc;

public:
	//c'tor
	Visit(Patient* patient, Date* date, char* purpose, Doctor* doc);
};

#endif