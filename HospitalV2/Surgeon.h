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
	//c'tor and d'tor
	Surgeon(const Doctor& base, int num_of_surgeries);
	Surgeon(const Surgeon& other);

	//getters and setters
	int getNumOfSurgeries() const;
	void addSurgery();

	//operators
	virtual void toOs(ostream& os) const override;

	//methods
	void show() const;
};

#endif
