#ifndef __Researcher_H
#define __Researcher_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Article;

class Researcher
{
private:
	static int counter; //unique id, starts from: 3000
	char* name;
	Article** articles;
	int id;
	int num_of_articles;

public:
	Researcher(char* n);
	~Researcher();

	//getters and setters
	char* getName() const;
	void setName(char* name);

	//methods
	void addArticle(Article* article);
};
#endif

