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
private:

public:
	//c'tor and d'tor
	DoctorResearcher(const Doctor& doc,const Researcher& researcher);

	//getters and setters


	//methods
	void show();

};

#endif