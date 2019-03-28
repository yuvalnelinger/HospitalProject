#include <iostream>
using namespace std;

#include "visit.h"

Visit::Visit(Patient* newPatient, Date* newDate, char* newPurpose, Doctor* newDoc)
{
	patient = newPatient;
	dateOfArrival = newDate;
	visitPurpose = newPurpose;
	treatingDoc = newDoc;
}
