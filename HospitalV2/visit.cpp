#include "visit.h"

//c'tor
Visit::Visit(Patient* patient, Date date, char* purpose, Doctor* doc, Nurse* nurse) : visitPurpose(nullptr), treatDoc(nullptr), treatNurse(nullptr)
{
	cout << "In Visit c'tor..." << endl;
	this->patient = patient;
	this->dateOfArrival = date;
	setVisitPurpose(purpose);
	this->treatDoc = doc;
	this->treatNurse = nurse;
}

//copy c'tor
Visit::Visit(const Visit& other)
{
	dateOfArrival = other.dateOfArrival;
	patient = other.patient;
	visitPurpose = new char[strlen(other.visitPurpose) + 1];
	strcpy(visitPurpose, other.visitPurpose);
	treatDoc = other.treatDoc;
	treatNurse = other.treatNurse;
}

//setters and getters
char* Visit::getVisitPurpose() const { return visitPurpose; }

void Visit::setVisitPurpose(const char* purpose)
{
	delete[] this->visitPurpose;
	this->visitPurpose = new char[strlen(purpose) + 1];
	strcpy(this->visitPurpose, purpose);
}