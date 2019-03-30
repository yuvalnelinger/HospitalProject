#ifndef __VISIT_H
#define __VISIT_H

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
	Visit(Patient* newPatient, Date* newDate, char* newPurpose, Doctor* newDoc);

};

#endif