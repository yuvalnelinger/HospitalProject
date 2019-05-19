#include "SurgeryVisit.h"

//c'tor
SurgeryVisit::SurgeryVisit(Patient* patient, Date date, char* purpose, StaffMember* doc, int roomNum, bool isFast) : Visit(patient, date, purpose, true,doc), roomNum(roomNum), isFast(isFast)
{
	cout << "In Surgery Visit c'tor..." << endl;
	this->roomNum = roomNum;
	this->isFast = isFast;
}
//copy c'tor
SurgeryVisit::SurgeryVisit(const SurgeryVisit& other)
{
	roomNum = other.roomNum;
	isFast = other.isFast;
}

SurgeryVisit::~SurgeryVisit()
{
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
