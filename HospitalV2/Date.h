#ifndef __Date_H
#define __Date_H

#include <iostream>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	//getters
	int getDay();
	int getMonth();
	int getYear();

	//setters
	bool setDay(int d);
	bool setMonth(int m);
	bool setYear(int y);

	//methods
	void show();
};

#endif
