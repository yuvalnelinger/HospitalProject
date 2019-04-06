#ifndef __Article_H
#define __Article_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Date.h"
using namespace std;

class Article
{
private:
	char* title;
	Date publish_date;
	char* name_of_magazine;

public:
	//c'tor and d'tor
	Article(Date p_date, char* title, char* name_of_magazine);
	~Article();

	//copy c'tor
	Article(const Article& other);

	//getters
	Date& getPublishDate();
	char* getTitle() const;
	char* getNameOfMagazine() const;

	//setters
	void setPublishDate(const Date& d);
	void setTitle(char* title);
	void setNameOfMagazine(char* magazine_name);

	//methods
	void show();
};
#endif __Article_H
