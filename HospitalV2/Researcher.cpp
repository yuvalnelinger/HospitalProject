#include "Researcher.h"

int Researcher::counter = 3000;

Researcher::Researcher(char* name)
{
	cout << "In Researcher c'tor..." << endl;
	id = counter++;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	articles = new Article*[size_of_articles];
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


