#ifndef __Date_H
#define __Date_H

#include <iostream>
using namespace std;
#define MAX_DAY_IN_MONTH 31
#define FIRST_DAY_IN_MONTH 1
#define MAX_MONTH 12
#define FIRST_MONTH 1
#define MAX_YEAR 2019
#define MIN_YEAR 1900

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
	void setDay(int d) throw (const char*);
	void setMonth(int m) throw (const char*);
	void setYear(int y) throw (const char*);

	//methods
	void show();
};

#endif
