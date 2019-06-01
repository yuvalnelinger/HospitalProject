#include "DoctorResearcher.h"

//c'tor and d'tor
DoctorResearcher::DoctorResearcher(const Doctor& doc, const Researcher& researcher) : StaffMember(doc.getName(), doc.getDepartment()), Doctor(doc), Researcher(researcher)
{}

void DoctorResearcher::toOs(ostream& os) const
{
	os << ", Specialty: " << specialty 
		<< ", Number of articles: " << articles.size()
		<< endl;
}

void DoctorResearcher::show() const
{
	Doctor::show();
}


