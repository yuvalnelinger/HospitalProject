#include "visit.h"

//c'tor
Visit::Visit(Patient* patient, Date date, string purpose, bool isSurgery,StaffMember* doc) : treatDoc(nullptr)
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
	visitPurpose = other.visitPurpose;
	treatDoc = other.treatDoc;
	isSurgery = other.isSurgery;
}

//setters and getters
string Visit::getVisitPurpose() const { return visitPurpose; }

void Visit::setVisitPurpose(const string purpose)
{
	this->visitPurpose = purpose;
}

bool Visit::getVisitType() const
{
	return isSurgery;
}