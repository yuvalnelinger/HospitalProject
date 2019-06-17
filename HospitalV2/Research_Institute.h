#ifndef __Research_Institute_H
#define __Research_Institute_H

#include "Researcher.h"
#include "Article.h"
#include "StaffMember.h"
#include "Date.h"
#include <iostream>
using namespace std;

class Research_Institute
{
private:
	vector<StaffMember*> researchers;
	vector<Article*> articles;

public:

	friend class Hospital; //The Researcher institue is associated with the hospital and has to have access to
						   //doctors that are also researchers.

	//c'tor and d'tor
	Research_Institute();
	~Research_Institute();

	//getters
	int getNumOfResearchers() const;
	int getNumOfArticles() const;
	StaffMember* getResearcherByIndex(int i);

	//methods
	void addResearcher(string name); //adds researcher ptr to the array
	void addArticle(Date date, string title, string name_of_magazine, int r_index);
	int searchResearcherByName(string name) const throw (const char*);
	void showResearchers() const;

private:
	//copy c'tor
	Research_Institute(const Research_Institute&); //prevent from user to make a copy of the RI
};

#endif