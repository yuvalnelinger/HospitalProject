#include "Researcher.h"

int Researcher::counter = 0;

Researcher::Researcher(char* n, Article** articles_arr, int size)
{
	id = ++counter;
	name = n;
	articles = articles_arr;
	num_of_articles = size;
}

Researcher::Researcher(char* n)
{
	id = ++counter;
	name = n;
	articles = new Article*[10];
	num_of_articles = 0;
}

Researcher::~Researcher()
{
	delete[]name;

	for (int i =0; i < num_of_articles; i++)
		delete articles[i];
	delete[]articles;
}

void Researcher::setName(char* n) { name = n; }

char* Researcher::getName() const { return name; }

void Researcher::addArticle(Article* article)
{
	articles[num_of_articles++] = article;
	//here shout be code for array increment!
}


