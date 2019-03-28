#include <iostream>
using namespace std;

#include <string.h>
#include "Date.h"
#include "Article.h"
#include "Research_Institute.h"
#include "Researcher.h"
#include "hospital.h"
#include "patient.h"
#include "visit.h"
#include "doctor.h"
#include "department.h"


#define MAX_TITLE 150
#define MAX_NAME 20
#define NOT_FOUND -1

int main()
{
	bool res;
	int day, month, year, len, r_index;
	Date date;
	char* name = new char[MAX_NAME];
	char* title = new char[MAX_TITLE];
	char* name_of_magazine = new char[MAX_NAME];
	char* search_name = new char[MAX_NAME];

	Hospital hospital;
	Department dep;
	/*Q1*/
	cout << "Adding a new department, choose name: " << endl;
	cin.getline(name, MAX_NAME);
	dep.setName(name);
	cout << "Successfully defined department name, adding department to hostpial" << endl;
	hospital.addDepartmentToHospital(&dep);
	hospital.show();
	/*End Q1*/
	/*Q3*/
	char* docName = new char[MAX_NAME];
	int docId;
	char* docSpecialty = new char[MAX_NAME];
	int depIndex;
	cout << "Adding a new doctor, choose name: " << endl;
	cin.getline(docName, MAX_NAME);
	cout << "Adding a new doctor, choose specialty: " << endl;
	cin.getline(docSpecialty, MAX_NAME);
	cout << "Adding a new doctor, choose ID: " << endl;
	cin >> docId;
	Doctor doc(docId, docName, docSpecialty);
	hospital.addDoctorToHospital(&doc);
	cout << "This is the list of departments in the hospital: " << endl;
	hospital.showDepartments();
	cout << "Insert the index of the department to add the doctor to " << endl;
	cin >> depIndex;
	hospital.getDepartmentByIndex(depIndex)->addDoctor(&doc);
	hospital.getDepartmentByIndex(depIndex)->show();

	/*End Q3*/

	/*Q4*/
	Patient* newPatient;
	Date visitDate;
	char* visPurpose=new char[MAX_NAME];
	Doctor* treatDoc;
	int patientID;
	cout << "Please enter Patient ID: " << endl;
	cin >> patientID;
	newPatient = hospital.getPatientByID(patientID);
	char* nameToAdd = new char[MAX_NAME];
	int newYear;
	eGender newGen;
	int genIndex;
	if (newPatient != 0)
	{
		cout << "Patient found" << endl;
	}
	else
	{
		cout << "Patient not found, enter details: " << endl;
		cout << "Enter Name: " << endl;
		cin.ignore();
		cin.getline(nameToAdd, MAX_NAME);
		cout << "Enter Year Of Birth: " << endl;
		cin >> newYear;
		cout << "Enter Gender (0 for MALE, 1 for FEMALE): " << endl;
		cin >> genIndex;
		newGen = (eGender)genIndex;
		cout << "Received details, creating Patient" << endl;
		newPatient = &Patient(nameToAdd, patientID, newYear, newGen);
	}
	cout << "Enter visit details. Visit date (day, month, year): " << endl;
	int newday, newmonth, newyear;
	cin >> newday >> newmonth >> newyear;
	visitDate.setDay(newday);
	visitDate.setMonth(newmonth);
	visitDate.setYear(newyear);
	cout << "Enter the visit purpose: " << endl;
	cin.ignore();
	cin.getline(visPurpose, MAX_NAME);
	cout << "Enter the Doctor ID: " << endl;
	int idToCheck;
	cin >> idToCheck;
	treatDoc = hospital.getDoctorByID(idToCheck);
	if (treatDoc != 0)
	{
		cout << "Doctor set." << endl;
	}
	else
	{
		cout << "Doctor not found, please create a new doctor" << endl;
		//add here the function to add new doctor to hospital and assign to treatDoc
	}
	Visit newVisit(newPatient, &visitDate, visPurpose, treatDoc);
	hospital.addVisitToHospital(&newVisit);
	cout << "What is the department the visit is to? insert the index of it " << endl;
	int patDep;
	hospital.showDepartments();
	cin >> patDep;
	Department* depToAdd = hospital.getDepartmentByIndex(patDep);
	depToAdd->addPatient(newPatient);
	hospital.addPatientToHospital(newPatient);
	cout << "Successfully added visit." << endl;
	hospital.show();

	/*End Q4*/

	Research_Institute resInstitute;

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
}