#include "Research_Institute.h"

Research_Institute::Research_Institute() {}

Research_Institute::~Research_Institute()
{
	int i;

	for (i = 0; i < researchers.size(); i++)
		delete researchers[i];

	for (i = 0; i < articles.size(); i++)
		delete articles[i];
}

int Research_Institute::getNumOfResearchers() const { return (int)researchers.size(); }

int Research_Institute::getNumOfArticles() const { return (int)articles.size(); }

StaffMember* Research_Institute::getResearcherByIndex(int i) { return this->researchers[i]; }

void Research_Institute::addResearcher(string name)
{
	Researcher* researcher = new Researcher(name);
	researchers.push_back(researcher); //add researcher to RI
	cout << "Successfully added researcher to the research institute" << endl;
}

void Research_Institute::addArticle(Date date, string title, string name_of_magazine, int r_index)
{
	Article* article = new Article(date, title, name_of_magazine);

	articles.push_back(article); //add article to the research institue
	researchers[r_index]->addArticle(article); //add article to researcher

	cout << "You have added the following article: " << endl;
	article->show();
	cout << "Article successfully added" << endl;
}

int Research_Institute::searchResearcherByName(string name) const throw (string)
{
	for (int i = 0; i < researchers.size(); i++)
	{
		if (researchers[i]->getName()== name)
		{
			return i;
		}
	}
	
	throw "Researcher not found, please try again";
}

void Research_Institute::showResearchers() const
{
	cout << "In the Research Institute there are " << researchers.size() << " researchers: \n";
	for (int i = 0; i < researchers.size(); i++)
	{
		cout << i + 1 << ". " << researchers[i]->getName().c_str() << endl;
	}
}
