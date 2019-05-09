#include "DoctorResearcher.h"

//c'tor and d'tor
DoctorResearcher::DoctorResearcher(const Doctor& doc, const Researcher& researcher) : StaffMember(doc.getName(), doc.getDepartment()), Doctor(doc), Researcher(researcher)
{}

DoctorResearcher::DoctorResearcher(const DoctorResearcher& other);

void DoctorResearcher::show()
{
	StaffMember::show();
	Doctor::show();
}


