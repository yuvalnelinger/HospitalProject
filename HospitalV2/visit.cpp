#include "visit.h"


Visit::Visit(Patient* newPatient, Date* newDate, char* newPurpose, Doctor* newDoc)
{
	cout << "In Visit c'tor..." << endl;
	patient = newPatient;
	dateOfArrival = newDate;
	visitPurpose = newPurpose;
	treatDoc = newDoc;
}