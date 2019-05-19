#include "SurgeonResearcher.h"

SurgeonResearcher::SurgeonResearcher(const Surgeon& surgeon, const Researcher& researcher) : StaffMember(surgeon.getName(),surgeon.getDepartment()),
																							 Surgeon(surgeon), Researcher(researcher) {}
void SurgeonResearcher::toOs(ostream& os) const
{
	os << ", Specialty: " << specialty
		<< ", Number of surgeries: " << num_of_surgeries
		<< ", Number of articles: " << num_of_articles
		<< endl;
}

void SurgeonResearcher::show() const
{
	Surgeon::show();
}