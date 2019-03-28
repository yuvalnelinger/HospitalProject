#ifndef __Research_Institute_H
#define __Research_Institute_H

#include <iostream>
using namespace std;

#include "Researcher.h"
#include "Article.h"

class Research_Institute
{
private:
	Researcher** researchers;
	int num_of_researchers;

	Article** articles;
	int num_of_articles;

public:
	//c'tor and d'tor
	Research_Institute();
	Research_Institute(Researcher** researchers_arr, int size);
	~Research_Institute();

	//getters
	int getNumOfResearchers() const;
	int getNumOfArticles() const;

	//methods
	void addResearcher(Researcher* researcher); //adds researcher ptr to the array
	void addArticleToInstitute(Article* article);
	void addArticleToResearcher(Article* article, int index);
	int searchResearcherByName(char* name) const;
	void show() const;
};

#endif