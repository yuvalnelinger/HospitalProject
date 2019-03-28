#ifndef __Article_H
#define __Article_H

#include <iostream>
using namespace std;

#include "Date.h"

class Article
{
private:
	char* title;
	Date publish_date;
	char* name_of_magazine;

public:
	//c'tor and d'tor
	Article(Date p_date, char* t, char* nm);
	~Article();

	//getters
	Date& getPublishDate();
	char* getTitle() const;
	char* getNameOfMagazine() const;

	//setters
	void setPublishDate(const Date& d);
	void setTitle(char* t);
	void setNameOfMagazine(char* nm);

	//methods
	void show();
};
#endif __Article_H
