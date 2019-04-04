#include "visit.h"

Visit::Visit(Patient* patient, Date* date, char* purpose, Doctor* doc)
{
	cout << "In Visit c'tor..." << endl;
	this->patient = patient;
	this->dateOfArrival = date;
	
	this->visitPurpose = new char[strlen(purpose) + 1];
	strcpy(this->visitPurpose, purpose);

	this->treatDoc = doc;
}