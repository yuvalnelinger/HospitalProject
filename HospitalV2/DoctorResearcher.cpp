#include "DoctorResearcher.h"

//c'tor and d'tor
DoctorResearcher::DoctorResearcher(const Doctor& doc, const Researcher& researcher) : StaffMember(doc.getName(), doc.getDepartment()), Doctor(doc), Researcher(researcher)
{}

//DoctorResearcher::DoctorResearcher(const DoctorResearcher& other);

void DoctorResearcher::toOs(ostream& os) const
{
	os << ", Specialty: " << specialty 
		<< ", Number of articles: " << num_of_articles
		<< endl;
}

void DoctorResearcher::show() const
{
	Doctor::show();
}


