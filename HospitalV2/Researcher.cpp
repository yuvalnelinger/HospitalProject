#include "Researcher.h"
#include "Article.h"

//c'tor and d'tor
Researcher::Researcher(char* name) : StaffMember(name, nullptr), size_of_articles(INIT_SIZE)
{
	articles = new Article*[size_of_articles];
	num_of_articles = 0;
}

Researcher::Researcher(const Researcher& other) : StaffMember(other)
{
	cout << "In Researcher::Researcher(copy)\n";
	*this = other;
}

Researcher::~Researcher()
{
	delete[]name;
	delete[]articles;
}

//getters and setters
//char* Researcher::getName() const { return name; }

//void Researcher::setName(char* name)
//{
//	delete[] this->name;
//	this->name = new char[strlen(name) + 1];
//	strcpy(this->name, name);
//}

//operators
const Researcher& Researcher::operator=(const Researcher& other)
{
	cout << "In Doctor::operator=" << endl;
	StaffMember::operator=(other);

	for (int i = 0; i < num_of_articles; i++)
		delete articles[i];
	
	delete[]articles;

	size_of_articles = other.size_of_articles;
	num_of_articles = other.num_of_articles;

	articles = new Article*[size_of_articles];
	for (int i = 0; i < num_of_articles; i++)
		articles[i] = other.articles[i];

	return *this;
}

bool Researcher::operator>(const Researcher& other) const
{
	return (this->num_of_articles > other.num_of_articles);
}


//methods
void Researcher::addArticle(Article* article)
{
	if (num_of_articles == size_of_articles) //array increment if needed
	{
		size_of_articles *= 2;
		Article** temp = new Article*[size_of_articles];
		for (int i = 0; i < num_of_articles; i++) //copy from old array to new array
			temp[i] = articles[i];
		delete[] articles;
		articles = temp;
	}
	articles[num_of_articles++] = article;
}

void Researcher::setDepartment(Department* depart)
{
	this->department == nullptr;
}


void Researcher::show() const
{
	StaffMember::show();
}



