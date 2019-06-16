#ifndef __INTERFACE_H
#define __INTERFACE_H

#define MAX_SIZE 100
#define _CRT_SECURE_NO_WARNINGS
#include "hospital.h"
#include <iostream>
#include <fstream>
using namespace std;

class Department;

class Interface
{
public:

static void mainMenu(Hospital& hospital);

	//menues print
static void printMainMenu();
static void printAddStaffMemberMenu();
static void printPatientsMenu();
static void printRIMenu();

	//cases
static void getDepartmentInfo(string* name);
static void getDoctorInfo(string* name, string* specialty, Department** depart, Hospital& hospital,bool* isSurgeon, bool* isResearcher, int* num_of_surgeries);
static void getNurseInfo(string* name, int* yearsExperience, Department** depart, Hospital& hospital);
static void getResearcherInfo(string* name);
static void getArticleInfo(string* title, string* name_of_magazine, Date* p_date, int* r_index, Hospital& hospital);
static void getVisitInfo(Patient** newPatient, Date* visitDate, string* visPurpose, Department** depToAdd, StaffMember** treatDoc, bool isNewPatient, bool* isFast, int* roomm,bool* isSurgery,Hospital& hospital);
static void compareResearchers(Research_Institute& RI);

	//utilities
static char* getInput();
static void isValid(int check, int lower, int upper) throw (const string);

//files methods
static void saveHospitalToFiles(Hospital& hospital);
};
#endif