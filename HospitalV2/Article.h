#ifndef __Article_H
#define __Article_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"
using namespace std;

class Article
{
private:
	string title;
	Date publish_date;
	string name_of_magazine;

public:
	//c'tor
	Article(Date p_date, const string title, const string name_of_magazine);

	//copy c'tor
	Article(const Article& other);

	//getters and setters
	Date& getPublishDate();
	string getTitle() const;
	string getNameOfMagazine() const;
	void setPublishDate(const Date& d);
	void setTitle(const string title);
	void setNameOfMagazine(const string magazine_name);

	//methods
	void show();
};
#endif __Article_H
