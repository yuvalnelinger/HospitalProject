#include "SurgeryVisit.h"

//c'tor and d'tor
SurgeryVisit::SurgeryVisit(Patient* patient, Date date, char* purpose, StaffMember* doc, int roomNum, bool isFast) : Visit(patient, date, purpose, true,doc), roomNum(roomNum), isFast(isFast)
{
	this->roomNum = roomNum;
	this->isFast = isFast;
}

SurgeryVisit::~SurgeryVisit()
{}

//copy c'tor
SurgeryVisit::SurgeryVisit(const SurgeryVisit& other)
{
	roomNum = other.roomNum;
	isFast = other.isFast;
}


//setters and getters
int SurgeryVisit::getRoomNum()
{
	return this->roomNum;
}

bool SurgeryVisit::getIsFast()
{
	return this->isFast;
}
