#include "Research_Institute.h"


Research_Institute::Research_Institute()
{
	cout << "In Research Institute c'tor" << endl;
	researchers = new Researcher*[10];
	num_of_researchers = 0;

	articles = new Article*[10];
	num_of_articles = 0;
}

//this is probably unuseful
Research_Institute::Research_Institute(Researcher** researchers_arr, int size)
{
	cout << "In Research Institute c'tor..." << endl;
	researchers = researchers_arr;
	num_of_researchers = size;
}

Research_Institute::~Research_Institute()
{
	cout << "In Research Institute d'tor..." << endl;
	int i;

	for (i = 0; i < num_of_researchers; i++)
		delete researchers[i];
	delete[]researchers;

	for (i = 0; i < num_of_articles; i++)
		delete articles[i];
	delete[]articles;
}

int Research_Institute::getNumOfResearchers() const { return num_of_researchers; }

int Research_Institute::getNumOfArticles() const { return num_of_articles; }

void Research_Institute::addResearcher(Researcher* researcher)
{
	researchers[num_of_researchers++] = researcher;
	//here should be code for array increment!
}

void Research_Institute::addArticle(Article* article)
{
	articles[num_of_articles++] = article;
	//here should be code for array increment!
}

//this method assign a pointer of article to a chosen researcher
void Research_Institute::addArticle(Article* article, int index)
{
	researchers[index]->addArticle(article);
}

int Research_Institute::searchResearcherByName(char* name) const
{
	for (int i = 0; i < num_of_researchers; i++)
	{
		if (strcmp(researchers[i]->getName(), name) == 0)
			return i;
	}

	return -1;
}

void Research_Institute::show() const
{
	cout << "In the Research Institute there are " << num_of_researchers << " researchers: \n";
	for (int i = 0; i < num_of_researchers; i++)
	{
		cout << i + 1 << ". " << researchers[i]->getName() << endl;
	}
}
