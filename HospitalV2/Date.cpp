#include "Date.h"

//qq- c'tor only for checks!
Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{}

//getters
int Date::getDay() { return day; }
int Date::getMonth() { return month; }
int Date::getYear() { return year; }

//setters
bool Date::setDay(int d)
{
	if (d < 1 || d > 31)
	{
		cout << "Day has to be between 1-31. please set day again" << endl;
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
	if (m < 1 || m > 12)
	{
		cout << "Month has to be between 1-12. please set month again" << endl;
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
	if (y < 1900 || y > 2019)
	{
		cout << "Year has to be between 1900-2019. please set year again" << endl;
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