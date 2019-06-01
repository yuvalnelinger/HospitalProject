#include "Researcher.h"
#include "Article.h"

//c'tor and d'tor
Researcher::Researcher(const char* name) : StaffMember(name, nullptr)
{
	//articles = new Article*[size_of_articles];
	//num_of_articles = 0;
}

Researcher::Researcher(const Researcher& other) : StaffMember(other)
{
	//for (int i = 0; i <articles.size(); i++)
	//	delete articles[i];

	//articles.clear();
	
	int logSize = other.articles.size();
	articles.reserve(logSize);
	
	//size_of_articles = other.size_of_articles;
	//num_of_articles = other.num_of_articles;

	//articles = new Article*[size_of_articles];
	for (int i = 0; i < logSize; i++)
	{
		//articles[i] = other.articles[i];
		articles.push_back(other.articles[i]);
	}
}

Researcher::~Researcher()
{
	//delete[]articles;
	articles.clear();
}

//operators
const Researcher& Researcher::operator=(const Researcher& other)
{
	StaffMember::operator=(other);

	for (int i = 0; i < articles.size(); i++)
		delete articles[i];
	
	//delete[]articles;
	articles.clear();

	//size_of_articles = other.size_of_articles;
	//num_of_articles = other.num_of_articles;

	int logSize = other.articles.size();
	articles.reserve(logSize);

	//articles = new Article*[size_of_articles];
	//for (int i = 0; i < num_of_articles; i++)
	//	articles[i] = other.articles[i];

	for (int i = 0; i < logSize; i++)
	{
		//articles[i] = other.articles[i];
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
	//if (num_of_articles == size_of_articles) //array increment if needed
	//{
	//	size_of_articles *= 2;
	//	Article** temp = new Article*[size_of_articles];
	//	for (int i = 0; i < num_of_articles; i++) //copy from old array to new array
	//		temp[i] = articles[i];
	//	delete[] articles;
	//	articles = temp;
	//}

	//articles[num_of_articles++] = article;
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



