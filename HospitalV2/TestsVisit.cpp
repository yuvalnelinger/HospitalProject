#include "TestsVisit.h"

//c'tor
TestsVisit::TestsVisit(Patient* patient, Date date, char* purpose, Doctor* doc, Nurse* nurse) : Visit(patient, date, purpose, doc, nurse)
{
}
//copy c'tor
TestsVisit::TestsVisit(const TestsVisit& other)
{
}

//setters and getters
