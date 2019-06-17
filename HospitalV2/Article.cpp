#include "Article.h"

//c'tor
Article::Article(Date p_date, const string title, const string name_of_magazine) 
{
	publish_date = p_date;
	setTitle(title);
	setNameOfMagazine(name_of_magazine);
}

//copy c'tor
Article::Article(const Article& other)
{
	title = other.title;

	name_of_magazine = other.name_of_magazine;

	publish_date = other.publish_date;
}

//getters and setters
Date& Article::getPublishDate() { return publish_date; }

string Article::getTitle() const { return title; }

string Article::getNameOfMagazine() const { return name_of_magazine; }

void Article::setPublishDate(const Date& d)
{
	this->publish_date = d;
}

void Article::setTitle(const string title)
{
	this->title = title;
}

void Article::setNameOfMagazine(const string name_of_magazine)
{
	this->name_of_magazine = name_of_magazine;
}

void Article::show()
{
	cout << "Title: " << title.c_str() << ", publish date: "; publish_date.show();
	cout << " published in magazine: " << name_of_magazine.c_str() << endl;
}
