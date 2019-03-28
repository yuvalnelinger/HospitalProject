#include "Research_Institute.h"
#include "Researcher.h"
#define NOT_FOUND -1

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
	cout << "In c'tor of Research Institute" << endl;
	researchers = researchers_arr;
	num_of_researchers = size;
}

Research_Institute::~Research_Institute()
{
	cout << "In d'tor of Research Institute" << endl;
	delete[]researchers;
}

int Research_Institute::getNumOfResearchers() const { return num_of_researchers; }

int Research_Institute::getNumOfArticles() const { return num_of_articles; }

void Research_Institute::addResearcher(Researcher* researcher)
{
	researchers[num_of_researchers++] = researcher;
	//here should be code for array increment!
}

void Research_Institute::addArticleToInstitute(Article* article)
{
	articles[num_of_articles++] = article;
	//here should be code for array increment!
}

//this method assign a pointer of article to a chosen researcher
void Research_Institute::addArticleToResearcher(Article* article, int index)
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

	return NOT_FOUND;
}

void Research_Institute::show() const
{
	cout << "In the Research Institute there are " << num_of_researchers << " researchers: \n";
	for (int i = 0; i < num_of_researchers; i++)
	{
		cout << i + 1 << ". " << researchers[i]->getName() << endl;
	}
}
