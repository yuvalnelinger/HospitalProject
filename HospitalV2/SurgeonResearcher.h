#ifndef __SURGESEARCHER_H
#define __SURGEEARCHER_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Surgeon.h"
#include "Researcher.h"

using namespace std;
class Department;

class SurgeonResearcher : public Surgeon, public Researcher
{
private:

public:
	//c'tor and d'tor
	SurgeonResearcher(const Surgeon& surgeon, const Researcher& researcher);

	//operators
	virtual void toOs(ostream& os) const override;

	//methods
	void show() const;
};

#endif
