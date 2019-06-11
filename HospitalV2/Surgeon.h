#ifndef __SURGEON_H
#define __SURGEON_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "doctor.h"

using namespace std;
class Department;

class Surgeon : virtual public Doctor
{
protected:
	int num_of_surgeries;

public:
	//c'tor
	Surgeon(const Doctor& base, int num_of_surgeries);
	Surgeon(ifstream& inFile);

	//getters
	int getNumOfSurgeries() const;
	void addSurgery();

	//operators
	virtual void toOs(ostream& os) const override;

	//methods
	void show() const;

protected:
	Surgeon(const Surgeon& other); //prevent from the user making a copy of a surgeon
};

#endif
