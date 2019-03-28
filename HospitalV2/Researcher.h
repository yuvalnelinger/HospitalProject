#ifndef __Researcher_H
#define __Researcher_H

#include <iostream>
using namespace std;

#include "Article.h"

class Researcher
{
private:
	static int counter; //unique id
	char* name;
	Article** articles;
	int id;
	int num_of_articles;

public:
	Researcher(char* n, Article** articles_arr, int size); //maybe this one isn't useful
	Researcher(char* n);
	~Researcher();

	//setters
	void setName(char* n);

	//getters (is there any need for that?)
	char* getName() const;

	//methods
	void addArticle(Article* article);
};
#endif

