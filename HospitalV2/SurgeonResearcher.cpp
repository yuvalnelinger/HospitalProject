#include "SurgeonResearcher.h"

//c'tor
SurgeonResearcher::SurgeonResearcher(const Surgeon& surgeon, const Researcher& researcher) : StaffMember(surgeon), Doctor(surgeon),Surgeon(surgeon), Researcher(researcher) {}

//operators
void SurgeonResearcher::toOs(ostream& os) const
{
	os << ", Specialty: " << specialty.c_str()
		<< ", Number of surgeries: " << num_of_surgeries
		<< ", Number of articles: " << articles.size()
		<< endl;
}

//methods
void SurgeonResearcher::show() const
{
	Surgeon::show();
}