#include "SurgeonResearcher.h"

SurgeonResearcher::SurgeonResearcher(const Surgeon& surgeon, const Researcher& researcher) : StaffMember(surgeon.getName()),Surgeon(surgeon), Researcher(researcher) {}
