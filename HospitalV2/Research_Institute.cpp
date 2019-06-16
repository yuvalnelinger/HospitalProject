#include "Research_Institute.h"

Research_Institute::Research_Institute()
{
	//researchers = new StaffMember*[size_of_researchers];
	//num_of_researchers = 0;
	//articles = new Article*[size_of_articles];
	//num_of_articles = 0;
}

Research_Institute::~Research_Institute()
{
	int i;

	for (i = 0; i < researchers.size(); i++)
		delete researchers[i];
	researchers.clear();

	for (i = 0; i < articles.size(); i++)
		delete articles[i];
	articles.clear();
}

int Research_Institute::getNumOfResearchers() const { return (int)researchers.size(); }

int Research_Institute::getNumOfArticles() const { return (int)articles.size(); }

StaffMember* Research_Institute::getResearcherByIndex(int i) { return this->researchers[i]; }

void Research_Institute::addResearcher(string name)
{
	//if (num_of_researchers == size_of_researchers) //array increment if needed
	//{
	//	size_of_researchers *= 2;
	//	StaffMember** temp = new StaffMember*[size_of_researchers];
	//	for (int i = 0; i < num_of_researchers; i++) //copy from old array to new array
	//		temp[i] = researchers[i];
	//	delete[] researchers;
	//	researchers = temp;
	//}

	Researcher* researcher = new Researcher(name);
	//researchers[num_of_researchers++] = researcher; //add researcher to RI
	researchers.push_back(researcher); //add researcher to RI
	cout << "Successfully added researcher to the research institute" << endl;
}

void Research_Institute::addArticle(Date date, string title, string name_of_magazine, int r_index)
{
	//if (num_of_articles == size_of_articles) //array increment if needed
	//{
	//	size_of_articles *= 2;
	//	Article** temp = new Article*[size_of_articles];
	//	for (int i = 0; i < num_of_articles; i++) //copy from old array to new array
	//		temp[i] = articles[i];
	//	delete[] articles;
	//	articles = temp;
	//}

	Article* article = new Article(date, title, name_of_magazine);

	//articles[num_of_articles++] = article; //add article to the research institue

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
