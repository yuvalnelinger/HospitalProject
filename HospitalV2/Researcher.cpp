#include "Researcher.h"
#include "Article.h"

//c'tor
Researcher::Researcher(string name) : StaffMember(name, nullptr) {}

Researcher::Researcher(const Researcher& other) : StaffMember(other)
{	
	int logSize = other.articles.size();
	articles.reserve(logSize);

	for (int i = 0; i < logSize; i++)
	{
		articles.push_back(other.articles[i]);
	}
}

//operators
const Researcher& Researcher::operator=(const Researcher& other)
{
	StaffMember::operator=(other);

	for (int i = 0; i < articles.size(); i++)
		delete articles[i];
	
	articles.clear();

	int logSize = other.articles.size();
	articles.reserve(logSize);

	for (int i = 0; i < logSize; i++)
	{
		articles.push_back(other.articles[i]);
	}

	return *this;
}

bool Researcher::operator>(const Researcher& other) const
{
	return (this->articles.size() > other.articles.size());
}

void Researcher::toOs(ostream& os) const
{
	os << ", Number of articles: " << articles.size()
		<< endl;
}

//methods
void Researcher::addArticle(Article* article)
{
	articles.push_back(article);
}

void Researcher::setDepartment(Department* depart)
{
	this->department = nullptr;
}

void Researcher::show() const
{
	StaffMember::show();
}



