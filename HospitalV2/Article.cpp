#include "Article.h"

//c'tor and d'tor
Article::Article(Date p_date, char* title, char* name_of_magazine) : title (nullptr), name_of_magazine (nullptr)
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

//copy c'tor
Article::Article(const Article& other)
{
	title = new char[strlen(other.title) + 1];
	strcpy(title, other.title);

	name_of_magazine = new char[strlen(other.name_of_magazine) + 1];
	strcpy(name_of_magazine, other.name_of_magazine);

	publish_date = other.publish_date;
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
	this->name_of_magazine = new char[strlen(name_of_magazine) + 1];
	strcpy(this->name_of_magazine, name_of_magazine);
}

void Article::show()
{
	cout << "Title: " << title << ", publish date: "; publish_date.show();
	cout << " published in magazine: " << name_of_magazine << endl;

}
