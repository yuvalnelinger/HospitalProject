#ifndef __Research_Institute_H
#define __Research_Institute_H

#include "Researcher.h"
#include "Article.h"
#include "Date.h"
#include <iostream>
using namespace std;
#define INIT_SIZE 50

class Research_Institute
{
private:
	Researcher** researchers;
	int size_of_researchers = INIT_SIZE;
	int num_of_researchers;

	Article** articles;
	int size_of_articles = INIT_SIZE;
	int num_of_articles;

public:
	//c'tor and d'tor
	Research_Institute();
	~Research_Institute();

	//getters
	int getNumOfResearchers() const;
	int getNumOfArticles() const;

	//methods
	void addResearcher(char* name); //adds researcher ptr to the array
	void addArticle(Date date, char* title, char* name_of_magazine, int r_index);
	int searchResearcherByName(char* name) const;
	void showResearchers() const;
};

#endif