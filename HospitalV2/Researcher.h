#ifndef __Researcher_H
#define __Researcher_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Article;
#define INIT_SIZE 50

class Researcher
{
private:
	static int counter; //unique id, starts from: 3000
	char* name;
	int id;
	Article** articles;
	int size_of_articles;
	int num_of_articles;

public:
	//c'tor and d'tor
	Researcher(char* name);
	~Researcher();

	//getters and setters
	char* getName() const;
	void setName(char* name);

	//methods
	void addArticle(Article* article);

private:
	Researcher(const Researcher&); //prevent from user to make a copy of researcher
};
#endif

