#include "Researcher.h"

int Researcher::counter = 3000;

Researcher::Researcher(char* name)
{
	cout << "In Researcher c'tor..." << endl;
	id = counter++;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	articles = new Article*[10];
	num_of_articles = 0;
}

Researcher::~Researcher()
{
	cout << "In Researcher d'tor..." << endl;
	delete[]name;
	delete[]articles;
}

char* Researcher::getName() const { return name; }

void Researcher::setName(char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Researcher::addArticle(Article* article)
{
	articles[num_of_articles++] = article;
	//here shout be code for array increment!
}


