#ifndef __Researcher_H
#define __Researcher_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StaffMember.h"
using namespace std;
class Article;
#define INIT_SIZE 50

class Researcher : virtual public StaffMember
{
protected:
	Article** articles;
	int size_of_articles;
	int num_of_articles;

public:
	//c'tor and d'tor
	Researcher(char* name);
	Researcher(const Researcher& other);
	~Researcher();

	//getters and setters
	//char* getName() const;
	//void setName(char* name);

	//methods
	void addArticle(Article* article);
	virtual void setDepartment(Department* depart) override;
	virtual void show() const override;


private:
	Researcher(const Researcher&); //prevent from user to make a copy of researcher
};
#endif

