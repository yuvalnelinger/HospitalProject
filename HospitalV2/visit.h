#ifndef __VISIT_H
#define __VISIT_H

#include <iostream>
using namespace std;

#include "date.h"
#include "doctor.h"
#include "patient.h"

class Visit
{
private:
	Patient* patient;
	Date* dateOfArrival;
	char* visitPurpose;
	Doctor* treatingDoc;
	//add nurse
public:
	//c'tor
	Visit(Patient* newPatient, Date* newDate, char* newPurpose, Doctor* newDoc);


};

#endif