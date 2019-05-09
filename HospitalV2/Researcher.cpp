#include "Researcher.h"

int Researcher::counter = 3000;

//c'tor and d'tor
Researcher::Researcher(char* name) : name(nullptr), size_of_articles(INIT_SIZE)
{
	id = counter++;
	setName(name);
	articles = new Article*[size_of_articles];
	num_of_articles = 0;
}

Researcher::~Researcher()
{
	delete[]name;
	delete[]articles;
}

//getters and setters
char* Researcher::getName() const { return name; }

void Researcher::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
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

void Researcher::show() const
{
	StaffMember::show();
}



