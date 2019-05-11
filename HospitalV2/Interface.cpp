#include "Interface.h"

//menues print
void Interface::printMainMenu()
{
	cout << "What would you like to do? please choose an option from the menu:" << endl;
	cout << "1. Add a department\n"
	 	<< "2. Add a staff member\n"
		<< "3. Patient operations\n"
		<< "4. Enter the research institute\n"
		<< "5. Show all staff members"
		<< endl;
}

void Interface::printAddStaffMemberMenu()
{
	cout << "What would you like to add? Choose the option from the menu:" << endl;
	cout << "1. Doctor\n"
		<< "2. Nurse"
		<< endl;
}

void Interface::printPatientsMenu()
{
	cout << "What operation would you like to perform?" << endl;
	cout << "1. Add a new visit\n"
	 	 << "2. Show all patients of a specific department\n"
		 << "3. Search patient by ID and get his details" << endl;
}

void Interface::printRIMenu()
{
	cout << "Welcome to the research institute! What would you like to do?" << endl;
	cout << "1. Add a researcher\n"
		<< "2. Add an article to a researcher\n"
		<< "3. Show all researchers"
		<< endl;
}

//cases
void Interface::getDepartmentInfo(char** name)
{
	cout << "Adding a new department, choose name: " << endl;
	*name = getInput();
}

void Interface::getDoctorInfo(char** name, char** specialty, Department** depart, Hospital& hospital,bool* isSurgeon,bool* isResearcher, int* num_of_surgeries)
{
	int depIndex;

	cout << "Adding a new doctor, choose name: " << endl;
	*name = getInput();
	cout << "Adding a new doctor, choose specialty: " << endl;
	*specialty = getInput();
	cout << "In which department is the doctor going to work? Insert the index" << endl;
	hospital.showDepartments();
	cin >> depIndex;

	while (!isValid(depIndex-1, 0, hospital.getNumOfDepartments()-1))
	{
		cout << "Invalid input. Please enter a valid department ID" << endl;
		cin >> depIndex;
	}

	*depart = hospital.getDepartmentByIndex(depIndex-1);
	cout << "Is this doctor a surgeon? press 1 for YES, 0 for NO" << endl;
	cin >> *isSurgeon;
	if (*isSurgeon==1)
	{
		cout << "How many surgeries did the surgeon perform?" << endl;
		cin >> *num_of_surgeries;

	}
	cout << "Is this doctor a researcher? press 1 for YES, 0 for NO" << endl;
	cin >> *isResearcher;
}

void Interface::getNurseInfo(char** name, int* yearsExperience, Department** depart, Hospital& hospital)
{
	int depIndex;

	cout << "Adding a new nurse, choose name: " << endl;
	*name = getInput();
	cout << "Adding a new nurse, type years of experience: " << endl;
	cin >> *yearsExperience;
	cout << "In which department is the nurse going to work? Insert the index" << endl;
	hospital.showDepartments();
	cin >> depIndex;

	while (!isValid(depIndex-1, 0, hospital.getNumOfDepartments()-1))
	{
		cout << "Invalid input. Please enter a valid department ID" << endl;
		cin >> depIndex;
	}

	*depart = hospital.getDepartmentByIndex(depIndex-1);
}

void Interface::getResearcherInfo(char** name)
{
	cout << "Please enter name:" << endl;
	*name = getInput();

}

void Interface::getArticleInfo(char** title, char** name_of_magazine, Date* p_date, int* r_index, Hospital& hospital)
{
	char* search_name = new char[MAX_NAME];
	cout << "To whom you would like to add the article? please type name:" << endl;
	search_name = getInput();

	*r_index = hospital.getResearchInstitute().searchResearcherByName(search_name);

	while (*r_index == NOT_FOUND)
	{
		cout << "There is no researcher with this name! please try again:" << endl;
		delete[] search_name;
		search_name = getInput();
		*r_index = hospital.getResearchInstitute().searchResearcherByName(search_name);
	}

	//researcher found
	cout << "Adding a new article for " << search_name << ":" << endl;
	cout << "What is the article's date?" << endl;

	int day, month, year;
	bool res;

	do {
		cout << "please enter day:" << endl;
		cin >> day;
		res = p_date->setDay(day);

	} while (res != true);

	do {
		cout << "please enter month:" << endl;
		cin >> month;
		res = p_date->setMonth(month);

	} while (res != true);

	do {
		cout << "please enter year:" << endl;
		cin >> year;
		res = p_date->setYear(year);

	} while (res != true);

	cout << "enter the title: " << endl;
	*title = getInput();
	cout << "enter the magazine's name: " << endl;
	*name_of_magazine = getInput();

	delete[] search_name;
}

void Interface::getVisitInfo(Patient** newPatient, Date* visitDate, char** visPurpose, Department** depToAdd, StaffMember** treatDoc, bool isNewPatient, Hospital& hospital)
{
	int patientID;
	char* nameToAdd = new char[MAX_NAME];
	int newYear = 0;
	int newGen = 0;
	int genIndex = 0;

	cout << "Adding a new visit, Please enter Patient ID (9 digits): " << endl;
	cin >> patientID;
	int numOfDigits = (int)log10((double)patientID) + 1;
	while (numOfDigits != 9)
	{
		cout << "Patint ID must be 9 digits. Please enter ID" << endl;
		cin >> patientID;
		numOfDigits = (int)log10((double)patientID) + 1;
	}
	*newPatient = hospital.getPatientByID(patientID);

	if (!*newPatient)
	{
		cout << "Patient not found, creating a new patient, enter details: " << endl;
		cout << "Enter Name: " << endl;
		nameToAdd = getInput();
		cout << "Enter Year Of Birth: " << endl;
		cin >> newYear;
		cout << "Enter Gender (0 for MALE, 1 for FEMALE): " << endl;
		cin >> genIndex;
		newGen = genIndex;
		cout << "Received details, creating Patient" << endl;
		*newPatient = new Patient(nameToAdd, patientID, newYear, newGen);
		isNewPatient = true;
		delete[] nameToAdd;
	}

	cout << "What is the department the visit is to? insert the index of it " << endl;
	int patDep;
	hospital.showDepartments();
	cin >> patDep;
	while (!isValid(patDep-1, 0, hospital.getNumOfDepartments()-1))
	{
		cout << "Invalid input. Please enter a valid department ID" << endl;
		cin >> patDep;
	}
	*depToAdd = hospital.getDepartmentByIndex(patDep-1);
	(*newPatient)->setCurrDepartment(*depToAdd);
	if ((*depToAdd)->getNumOfStaffMembers() == 0)
	{
		cout << "No staff in this department yet. Please add staff" << endl;
		int selection;
		printAddStaffMemberMenu();
		cin >> selection;
		while (!isValid(selection, 1, 2))
		{
			cout << "Invalid input, select between Nurse to Doctor" << endl;
			cin >> selection;
		}
		char* name = new char[MAX_NAME];
		bool isSurgeon;
		bool isResearcher;
		int num_of_surgeries;
		if (selection == 1)
		{
			char* docSpecialty = new char[MAX_NAME];
			Interface::getDoctorInfo(&name, &docSpecialty, depToAdd, hospital,&isSurgeon,&isResearcher,&num_of_surgeries);
			hospital.addDoctor(name, docSpecialty, *depToAdd,isSurgeon,isResearcher,num_of_surgeries);
			delete[] name;
			delete[] docSpecialty;
		}
		else
		{
			int yearsExperience;
			Interface::getNurseInfo(&name, &yearsExperience, depToAdd, hospital);
			hospital.addNurse(name, yearsExperience, *depToAdd);
			delete[] name;
		}

	}
	cout << "Enter visit details. Visit date (day, month, year): " << endl;
	int day, month, year;
	bool res;
	do {
		cout << "please enter day:" << endl;
		cin >> day;
		res = visitDate->setDay(day);

	} while (res != true);

	do {
		cout << "please enter month:" << endl;
		cin >> month;
		res = visitDate->setMonth(month);

	} while (res != true);

	do {
		cout << "please enter year:" << endl;
		cin >> year;
		res = visitDate->setYear(year);

	} while (res != true);

	cout << "Enter the visit purpose: " << endl;
	*visPurpose = getInput();

	int idToCheck;
	cout << "This is the list of doctors and nurses you can choose from:" << endl;
	(*depToAdd)->showStaff();
	   
	cout << "Enter the staff member ID: " << endl;
	cin >> idToCheck;
	*treatDoc = hospital.getStaffMemberByID(idToCheck);

	while (*treatDoc == 0)
		{
			cout << "Couldn't find staff member, insert ID of doctor/nurse from the list above." << endl;
			cin >> idToCheck;
			*treatDoc = hospital.getStaffMemberByID(idToCheck);
		}
	cout << "Staff member set as treating staff." << endl;

}

//utilities
char* Interface::getInput()
{
	char* input = new char[MAX_SIZE];
	cin.ignore();
	cin.getline(input, MAX_SIZE);
	char* resized_input = new char[strlen(input)+1];
	strcpy(resized_input, input);
	delete[]input;
	input = resized_input;

	return input;
}

bool Interface::isValid(int check, int lower, int upper)
{
	return (lower <= check) && (check <= upper);
}