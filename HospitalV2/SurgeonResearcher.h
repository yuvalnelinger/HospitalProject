#pragma warning(disable: 4250)		//disable warning C4250 - inheritance via dominance
									//warning related to diamond inheritance
#ifndef __SURGESEARCHER_H
#define __SURGEEARCHER_H

#define _CRT_SECURE_NO_WARNINGS
#include "Researcher.h"
#include "Surgeon.h"
#include <iostream>

using namespace std;
class Department;

class SurgeonResearcher : public Surgeon, public Researcher
{
private:

public:
	//c'tor
	SurgeonResearcher(const Surgeon& surgeon, const Researcher& researcher);

	//operators
	virtual void toOs(ostream& os) const override;

	//methods
	void show() const;

private:
	SurgeonResearcher(const SurgeonResearcher& other); //prevent making a copy
};

#endif
