#include "visit.h"

//c'tor
Visit::Visit(Patient* patient, Date date, char* purpose, bool isSurgery,StaffMember* doc) : visitPurpose(nullptr), treatDoc(nullptr)
{
	this->patient = patient;
	this->dateOfArrival = date;
	setVisitPurpose(purpose);
	this->isSurgery = isSurgery;
	this->treatDoc = doc;
}

Visit::Visit() : visitPurpose(nullptr), treatDoc(nullptr)
{
	this->patient = 0;
	this->dateOfArrival = Date();
}



//copy c'tor
Visit::Visit(const Visit& other)
{
	dateOfArrival = other.dateOfArrival;
	patient = other.patient;
	visitPurpose = new char[strlen(other.visitPurpose) + 1];
	strcpy(visitPurpose, other.visitPurpose);
	treatDoc = other.treatDoc;
	isSurgery = other.isSurgery;
}

//setters and getters
char* Visit::getVisitPurpose() const { return visitPurpose; }

void Visit::setVisitPurpose(const char* purpose)
{
	delete[] this->visitPurpose;
	this->visitPurpose = new char[strlen(purpose) + 1];
	strcpy(this->visitPurpose, purpose);
}

bool Visit::getVisitType() const
{
	return isSurgery;
}