#include "Date.h"

//getters
int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }

//setters
void Date::setDay(int d) throw (const char*)
{
	if (d < FIRST_DAY_IN_MONTH || d > MAX_DAY_IN_MONTH)
	{
		cout << "Day has to be between " << FIRST_DAY_IN_MONTH << "-" << MAX_DAY_IN_MONTH <<". " << "please set day again" << endl;
		throw "Please try again";
	}
	else
	{
		day = d;
	}
}

void Date::setMonth(int m) throw (const char*)
{
	if (m < FIRST_MONTH || m > MAX_MONTH)
	{
		cout << "Month has to be between " << FIRST_MONTH << "-" << MAX_MONTH << ". " << "please set month again" << endl;
		throw "Please try again";
	}
	else
	{
		month = m;
	}
}

void Date::setYear(int y) throw (const char*)
{
	if (y < MIN_YEAR || y > MAX_YEAR)
	{
		cout << "Year has to be between " << MIN_YEAR << "-" << MAX_YEAR << ". " << "please set year again" << endl;
		throw "Please try again";
	}
	else
	{
		year = y;
	}
}

//methods
void Date::show()
{
	cout << day << "/" << month << "/" << year;
}