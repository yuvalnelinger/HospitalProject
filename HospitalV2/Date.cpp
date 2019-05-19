#include "Date.h"

//getters
int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }

//setters
bool Date::setDay(int d)
{
	if (d < FIRST_DAY_IN_MONTH || d > MAX_DAY_IN_MONTH)
	{
		cout << "Day has to be between " << FIRST_DAY_IN_MONTH << "-" << MAX_DAY_IN_MONTH <<". " << "please set day again" << endl;
		return false;
	}
	else
	{
		day = d;
		return true;
	}
}

bool Date::setMonth(int m)
{
	if (m < FIRST_MONTH || m > MAX_MONTH)
	{
		cout << "Month has to be between " << FIRST_MONTH << "-" << MAX_MONTH << ". " << "please set month again" << endl;
		return false;
	}
	else
	{
		month = m;
		return true;
	}
}

bool Date::setYear(int y)
{
	if (y < MIN_YEAR || y > MAX_YEAR)
	{
		cout << "Year has to be between " << MIN_YEAR << "-" << MAX_YEAR << ". " << "please set year again" << endl;
		return false;
	}
	else
	{
		year = y;
		return true;
	}
}

//methods
void Date::show()
{
	cout << day << "/" << month << "/" << year;
}