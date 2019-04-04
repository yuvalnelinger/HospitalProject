#ifndef __Researcher_H
#define __Researcher_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
class Article;
#define INIT_SIZE 10

class Researcher
{
private:
	static int counter; //unique id, starts from: 3000
	char* name;
	int id;
	Article** articles;
	int size_of_articles = INIT_SIZE;
	int num_of_articles;

public:
	Researcher(char* name);
	~Researcher();

	//getters and setters
	char* getName() const;
	void setName(char* name);

	//methods
	void addArticle(Article* article);
};
#endif

