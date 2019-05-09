#ifndef __INTERFACE_H
#define __INTERFACE_H

#define MAX_SIZE 100
#define _CRT_SECURE_NO_WARNINGS
#include "hospital.h"
#include <iostream>
using namespace std;

class Department;

class Interface
{
public:
	//menues print
static void printMainMenu();
static void printAddStaffMemberMenu();
static void printPatientsMenu();
static void printRIMenu();

	//cases
static void getDepartmentInfo(char** name);
static void getDoctorInfo(char** name, char** specialty, Department** depart, Hospital& hospital,bool* isSurgeon, bool* isResearcher);
static void getNurseInfo(char** name, int* yearsExperience, Department** depart, Hospital& hospital);
static void getResearcherInfo(char** name);
static void getArticleInfo(char** title, char** name_of_magazine, Date* p_date, int* r_index, Hospital& hospital);
static void getVisitInfo(Patient** newPatient, Date* visitDate, char** visPurpose, Department** depToAdd, Doctor** treatDoc, Nurse** treatNurse, bool isNewPatient, Hospital& hospital);

	//utilities
static char* getInput();
static bool isValid(int check, int lower, int upper);

};
#endif