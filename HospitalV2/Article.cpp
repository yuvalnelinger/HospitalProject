#include "Article.h"

Article::Article(Date p_date, char* t, char* nm)
{
	publish_date = p_date;
	title = t;
	name_of_magazine = nm;
}

Article::~Article()
{
	delete[]title;
	delete[]name_of_magazine;
}

Date& Article::getPublishDate() { return publish_date; }

char* Article::getTitle() const { return title; }

char* Article::getNameOfMagazine() const { return name_of_magazine; }

void Article::setPublishDate(const Date& d)
{
	publish_date = d;
}

void Article::setTitle(char* t)
{
	title = t;
}

void Article::setNameOfMagazine(char* nm)
{
	name_of_magazine = nm;
}

void Article::show()
{
	cout << "Title: " << title << ", publish date: "; publish_date.show();
	cout << " published in magazine: " << name_of_magazine << endl;

}
