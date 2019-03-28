#include <iostream>
using namespace std;

#include <string.h>

#include "Date.h"
#include "Article.h"
#include "Research_Institute.h"
#include "Researcher.h"
#include "department.h"
#include "doctor.h"
#include "patient.h"
#include "visit.h"

#define MAX_TITLE 150
#define MAX_NAME 20
#define NOT_FOUND -1

int main()
{
	/*Add dep to hospital*/
	Department dep;
	char* name[20];
	cout << "Please set a name for the department (up to 20 chars): " << endl;
	cin.getline(name,MAX_NAME);

	
	/*
	cout << "Research Institute is now OPEN! let's add some researchers and articles!" << endl;
	cout << "You chose to add a new researcher, let's do this. please enter his/her name (up to 20 characters):" << endl;

	cin.getline(name, MAX_NAME);

	//resize string to logic size - create func for this
	len = strlen(name);
	char* newName = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		newName[i] = name[i];
	newName[len] = '\0'; //lock string
	delete[]name;
	name = newName;

	Researcher r1(name);
	resInstitute.addResearcher(&r1);

	resInstitute.show();

	cout << "Okay. Now you chose to add an article to a researcher." << endl;
	cout << "To whom you would like to add?" << endl;

	cin.getline(search_name, MAX_NAME);

	//resize string to logic size - create func for this
	len = strlen(search_name);
	char* new_search_name = new char[len + 1];
	for (int i = 0; i < len + 1; i++)
		new_search_name[i] = search_name[i];
	new_search_name[len] = '\0'; //lock string
	delete[]search_name;
	search_name = new_search_name;

	//look for this name - found/not found
	r_index = resInstitute.searchResearcherByName(search_name);
	if (r_index == NOT_FOUND)
	{
		cout << "There is no researcher in this name! try again..." << endl;
		exit(1);
	}
	else
	{
		cout << "let's add a new article for " << search_name << "!" << endl;
		cout << "What is the article's date?" << endl;
		do {
			cout << "please enter day:" << endl;
			cin >> day;
			res = date.setDay(day);

		} while (res != true);

		do {
			cout << "please enter month:" << endl;
			cin >> month;
			res = date.setMonth(month);

		} while (res != true);

		do {
			cout << "please enter year:" << endl;
			cin >> year;
			res = date.setYear(year);

		} while (res != true);

		cout << "enter the title: " << endl;
		getchar();
		cin.getline(title, MAX_TITLE);

		//resize string to logic size
		len = strlen(title);
		char* newtitle = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
			newtitle[i] = title[i];
		newtitle[len] = '\0'; //lock string
		delete[]title;
		title = newtitle;

		cout << "enter the magazine's name: " << endl;
		cin.getline(name_of_magazine, MAX_NAME);

		//resize string to logic size
		len = strlen(name_of_magazine);
		char* newnm = new char[len + 1];
		for (int i = 0; i < len + 1; i++)
			newnm[i] = name_of_magazine[i];
		newnm[len] = '\0'; //lock string
		delete[]name_of_magazine;
		name_of_magazine = newnm;

		Article a(date, title, name_of_magazine);
		a.show();

		resInstitute.addArticleToInstitute(&a);
		resInstitute.addArticleToResearcher(&a, r_index);

	}
	return(0);
	*/
}