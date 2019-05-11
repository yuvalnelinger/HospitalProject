#include "SurgeonResearcher.h"

SurgeonResearcher::SurgeonResearcher(const Surgeon& surgeon, const Researcher& researcher) : StaffMember(surgeon.getName(),surgeon.getDepartment()),Surgeon(surgeon), Researcher(researcher) {}

void SurgeonResearcher::show() const
{
	Surgeon::show();
	Researcher::show();
}