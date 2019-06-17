#pragma warning(disable: 4250)		//disable warning C4250 - inheritance via dominance
									//warning related to diamond inheritance

#ifndef __DOCSEARCHER_H
#define __DOCSEARCHER_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "doctor.h"
#include "Researcher.h"
using namespace std;

class Department;

class DoctorResearcher : public Doctor, public Researcher
{

public:
	//c'tor and d'tor
	DoctorResearcher(const Doctor& doc, const Researcher& researcher);

	//operators
	virtual void toOs(ostream& os) const override;

	//methods
	void show() const;

private:
	DoctorResearcher(const DoctorResearcher& other); //prevent from the user making a copy of a doctor-researcher
};

#endif
