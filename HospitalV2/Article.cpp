#include "Article.h"


Article::Article(Date p_date, char* title, char* name_of_magazine)
{
	cout << "In Article c'tor..." << endl;
	publish_date = p_date;
	setTitle(title);
	setNameOfMagazine(name_of_magazine);
}

Article::~Article()
{
	cout << "In Article d'tor..." << endl;
	delete[]title;
	delete[]name_of_magazine;
}

Date& Article::getPublishDate() { return publish_date; }

char* Article::getTitle() const { return title; }

char* Article::getNameOfMagazine() const { return name_of_magazine; }

void Article::setPublishDate(const Date& d)
{
	this->publish_date = d;
}

void Article::setTitle(char* title)
{
	delete[] this->title;
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
}

void Article::setNameOfMagazine(char* name_of_magazine)
{
	delete[] this->name_of_magazine;
	this->title = new char[strlen(name_of_magazine) + 1];
	strcpy(this->name_of_magazine, name_of_magazine);
}

void Article::show()
{
	cout << "Title: " << title << ", publish date: "; publish_date.show();
	cout << " published in magazine: " << name_of_magazine << endl;

}
