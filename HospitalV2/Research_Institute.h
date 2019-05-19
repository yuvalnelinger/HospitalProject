#ifndef __Research_Institute_H
#define __Research_Institute_H

#define INIT_SIZE 50
#include "Researcher.h"
#include "Article.h"
#include "StaffMember.h"
#include "Date.h"
#include <iostream>
using namespace std;

class Research_Institute
{
private:
	StaffMember** researchers;
	int size_of_researchers;
	int num_of_researchers;
	Article** articles;
	int size_of_articles;
	int num_of_articles;

public:
	friend class Hospital;
	//c'tor and d'tor
	Research_Institute();
	~Research_Institute();

	//getters
	int getNumOfResearchers() const;
	int getNumOfArticles() const;
	StaffMember* getResearcherByIndex(int i);

	//methods
	void addResearcher(char* name); //adds researcher ptr to the array
	void addArticle(Date date, char* title, char* name_of_magazine, int r_index);
	int searchResearcherByName(char* name) const;
	void showResearchers() const;

private:
	Research_Institute(const Research_Institute&); //prevent from user to make a copy of the RI
};

#endif