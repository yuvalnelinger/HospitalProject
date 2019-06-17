#ifndef __Researcher_H
#define __Researcher_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include "StaffMember.h"
using namespace std;

class Article;

class Researcher : virtual public StaffMember
{
protected:
	vector<Article*> articles;

public:
	//c'tor and d'tor
	Researcher(string name);

	//operators
	const Researcher& operator=(const Researcher& other);
	bool operator>(const Researcher& other) const;
	virtual void toOs(ostream& os) const override;

	//methods
	virtual void addArticle(Article* article);
	virtual void setDepartment(Department* depart) override;
	virtual void show() const override;

protected:
	//copy c'tor
	Researcher(const Researcher& other); //prevent from the user making a copy of a reseacher
};
#endif

